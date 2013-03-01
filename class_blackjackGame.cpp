#include <vector> // Used in hands
#include <iostream>

#include "class_blackjackGame.h"
#include "class_deck.h"
#include "class_card.h"
#include "gameTypes.h"
#include "class_blackjackState.h"
#include "class_blackjackAction.h"

    using namespace casino;

    blackjackGame::blackjackGame(int players) : game(blackjack, players) {
        // Passing parameter to game
    };
        

    void blackjackGame::playRound(){
        // Setting up variabels
        std::vector<std::vector<cards::card> > dealtcards;
        int player = 0;
        int dealer = 1;
        float playerCash = 0;
        
        //Dealing
        dealtcards.push_back(std::vector<cards::card>());   // Initializing vector in vector
        dealtcards.push_back(std::vector<cards::card>());   // Initializing vector in vector
        dealtcards.at(player).push_back(deck.deal());       // Dealing to player
        dealtcards.at(dealer).push_back(deck.deal());       // Dealing to dealer
        dealtcards.at(player).push_back(deck.deal());       
        dealtcards.at(dealer).push_back(deck.deal());

        //It's all about the State!
        gameState* gstate = new blackjackState(dealtcards, player, dealer); 
        //blackjackState* bstate = (blackjackState*) &gstate;

        //Placing bet from the one player implemented here
        gamblers[0].giveMoney(0);
        playerCash = gamblers[0].placeBet();
        bool gotMoney = true;
        while(playerCash < 1 && playerCash != -1){
            playerCash = gamblers[0].placeBet();
        }
        if(playerCash == -1){
            std::cout << "You don't have any money left. You have lost!" << std::endl;
            gotMoney = false;
        }
        std::cout << std::endl;

        bool isDone = 0;
        while(gotMoney && handValue(dealtcards.at(player)) < 21 && isDone == 0){
            action* a = gamblers[0].takeAction(gstate);
            blackjackAction* action = static_cast<blackjackAction*>(a);

            if(action->getAtype() == blackjackAction::HIT){
                dealtcards.at(player).push_back(deck.deal());
                delete gstate;
                gstate = new blackjackState(dealtcards, player, dealer);
            }
            else if(action->getAtype() == blackjackAction::STAND){
                isDone = 1;
            //}else if(action->getAtype() == blackjackAction::DOUBLE){
                
            }
            delete action;
        }

        // The house is playing
        while(blackjackGame::handValue(dealtcards.at(dealer)) < 17){
            dealtcards.at(dealer).push_back(deck.deal());
            delete gstate;
            gstate = new blackjackState(dealtcards, player, dealer);
        }

        
        int playerFinalScore = handValue(dealtcards.at(player));
        int dealerFinalScore = handValue(dealtcards.at(dealer));
        
        if(gotMoney){
        std::cout << std::endl;
        // If the player has BLACKJACK
        if(playerFinalScore == 21 && dealtcards.at(player).size() == 2){
            std::cout << "\tBLACKJACK! Player won " << (playerCash + playerCash*1.5) << " cash" << std::endl;
            gamblers[0].giveMoney(playerCash + playerCash*1.5);
        }
        // The dealer busts
        else if(playerFinalScore <= 21 && dealerFinalScore > 21){
            std::cout << "\tDealer busted. You won " << playerCash << " cash" << std::endl;
            gamblers[0].giveMoney(playerCash + playerCash);
        }
        // The user busts
        else if(playerFinalScore > 21){
            std::cout << "\tYou busted. Dealer won " << playerCash << " cash"<< std::endl;
            // Add money to the dealer (house)
        }
        // Dealer won.
        else if(dealerFinalScore <= 21 && dealerFinalScore > playerFinalScore){
            std::cout << "\tDealer won with total score of " << dealerFinalScore << " points!" << std::endl;
            // Add money to the dealer (house)
        }
        // Player won
        else if(playerFinalScore <= 21 && playerFinalScore > dealerFinalScore){
            std::cout << "\tPlayer won with total score of " << playerFinalScore << " points!" << std::endl;
            gamblers[0].giveMoney(playerCash + playerCash);
        }
        // Push
        else if(playerFinalScore == dealerFinalScore){
            std::cout << "\tPush. Nobody won" << std::endl;
            gamblers[0].giveMoney(playerCash); // Get back only the effort
        }

        std::cout << std::endl << "\tPlayer score:\t" << playerFinalScore << std::endl;
        std::cout << "\tDealer score:\t" << dealerFinalScore << std::endl;
        }
        delete gstate;
    }

    void blackjackGame::start(){
        // Setting up the deck
        deck = cards::deck();

        // Everyday I'm shuffeling
        deck.shuffle();

        // while playing some rounds m'kay
        try{
            std::string* s = new std::string();
            *s = "y";
        
            while(*s == "Y" || *s == "y"){
                playRound();

                std::cout << std::endl << "Play another round? (y/n): ";
                std::cin >> *s;
                std::cout << std::endl;
            }
            gamblers[0].giveMoney(0);
            delete s;
        }catch(int e){
        }
    }

    int blackjackGame::handValue(std::vector<cards::card> c){
        // Gets the *best* value for the hand. Not posible to split any cards here! Sorry
        int handTotal = 0;
        int currentValue = 0;
        std::vector<cards::card> ace;

        // Iterating over the hand of cards (using iterator since we could remove the card)
        for(std::vector<cards::card>::iterator it = c.begin(); it != c.end(); ++it){
            currentValue = cardPoints(*it); // Getting the value of a single card
            if(currentValue == 11){
                ace.push_back(*it);
            }
            if(currentValue != 11 && currentValue > 0){
                handTotal += currentValue;
            }
            currentValue = 0;
        }

        // Handling the aces since it is a special case
        if(ace.size() > 0){
            if(ace.size() > 1){
                if(handTotal < (11 - ace.size()))
                {
                    handTotal += 11;
                    handTotal += (ace.size()-1);
                }
                else{
                    handTotal += ace.size(); 
                }
            }else{
                if(handTotal > 10){
                    handTotal += 1;
                }else{
                    handTotal += 11;
                }
            }
        }
        return handTotal;
    }

    int blackjackGame::cardPoints(cards::card c){
        for(int i = 0; i < cards::NUM_RANKS; i++){
            if(cards::ranks[i] == c.getRank()){
                if(i < 8){
                    return i+2;
                }
                else if(i > 7 && cards::ranks[i] != 'A'){
                    return 10;
                }
                else if(cards::ranks[i] == 'A'){
                    return 11;
                }
            }
        }
        return 0;
    }
