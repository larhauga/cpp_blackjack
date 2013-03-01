#include <vector> // Used in hands
#include <iostream>

#include "class_blackjackGame.h"
#include "class_deck.h"
#include "class_card.h"
#include "gameTypes.h"
#include "class_blackjackState.h"
#include "class_blackjackAction.h"

namespace casino{

    blackjackGame::blackjackGame(int players) : game(blackjack, players) {
    
    };
        

    void blackjackGame::playRound(){
        // Fixing vectors
        std::vector<cards::card> dealer;
        std::vector<cards::card> player;
        std::vector<std::vector<cards::card> > cards;
        
        //Dealing
        player.push_back(deck.deal());
        dealer.push_back(deck.deal());
        player.push_back(deck.deal());
        dealer.push_back(deck.deal());
        cards.push_back(player);
        cards.push_back(dealer);

        //It's all about the State!
        gameState* state;
        state = new blackjackState(cards, 0, 1); 
        int score_dealer = 0;
        int score_player = 0;


        action* a = gamblers[0].takeAction(state);
        a->print();
        blackjackAction* bla = static_cast<blackjackAction*>(a);
        blackjackAction::atype b = bla->getAtype();
        
        //blackjackAction::atype ty = *a.getAtype();
        std::cout << b << std::endl;
/*
        std::string inState = "";
        // Playing with a player
        while(blackjackGame::handValue(player) < 21 && inState != "STAND"){
            score_dealer = blackjackGame::handValue(dealer);
            score_player = blackjackGame::handValue(player);

            if(score_player > 21){
                inState = "STAND";
            }else{

                // Print the state of things
                state->print();
            
                std::cout << "HIT or STAND: ";
                inState = "";
                std::cin >> inState;

                if(inState == "HIT"){
                    cards::card c = deck.deal();
                    cards[0].push_back(c);
                    player.push_back(c);
                    state = new blackjackState(cards, 0, 1);
                    score_player = blackjackGame::handValue(player);
                }
            }
        }
*/        
        // The house is playing
        while(blackjackGame::handValue(dealer) < 17){
            cards::card c = deck.deal();
            cards[1].push_back(c);
            dealer.push_back(c);
            state = new blackjackState(cards, 0, 1);
            score_dealer = blackjackGame::handValue(dealer);
        }

        if(score_player == 21){
            std::cout << "BLACKJACK! Player won!" << std::endl;
        }
        else if(score_dealer <= 21 && score_dealer > score_player){
            std::cout << "Dealer won with total score of " << score_dealer << " points!" << std::endl;
        }
        else if(score_player <= 21 && score_player > score_dealer){
            std::cout << "Player won with total score of " << score_player << " points!" << std::endl;
        }
        else if(score_player > 21 && score_dealer > 21){
            std::cout << "Went skyhigh and no one won!" << std::endl;
        }
        else if(score_player == score_dealer){
            std::cout << "Push..." << std::endl;
        }

        std::cout << "Player score: " << score_player << std::endl;
        std::cout << "Dealer score: " << score_dealer << std::endl;
        
        delete state;
        delete a;

    }

    void blackjackGame::start(){
        // Setting up the deck
        deck = cards::deck(2);

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
            }
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

    // This function is right now not a part of the class
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
}
