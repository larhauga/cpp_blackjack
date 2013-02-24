#include <vector> // Used in hands
#include "class_deck.h"
#include "class_card.h"
#include "class_blackjackGame.h"
#include "gameTypes.h"
#include <iostream>

namespace casino{

    blackjackGame::blackjackGame(int players) : game(blackjack, players) {
    
    };
        

    void blackjackGame::playRound(){
        // Do something
        std::vector<cards::card> dealer;
        std::vector<cards::card> player;
        
        //Dealing
        player.push_back(deck.deal());
        dealer.push_back(deck.deal());
        player.push_back(deck.deal());
        dealer.push_back(deck.deal());

        int score_dealer = blackjackGame::handValue(dealer);
        int score_player = blackjackGame::handValue(player);

        std::cout << "Player score: " << score_player << std::endl;
        std::cout << "Dealer score: " << score_dealer << std::endl;
        if(score_player == 21){
            std::cout << "BLACKJACK! Player won!" << std::endl;
        }
        else if(score_dealer <= 21 &&score_dealer > score_player){
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
        
    }
    void blackjackGame::start(){
        // Setting up the deck
        deck = cards::deck(2);

        // Everyday I'm shuffeling
        deck.shuffle();

        std::vector<cards::card> v;

        playRound();
        // while playing some rounds m'kay
    }

    int blackjackGame::handValue(std::vector<cards::card> c){
        // Gets the *best* value for the hand. Not posible to split any cards here! Sorry
        int handTotal = 0;
        int currentValue = 0;
        std::vector<cards::card> ace;

        // Iterating over the hand of cards
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

        if(ace.size() > 0){
            if(ace.size() > 1){
                if(handTotal < (11 - ace.size()))
                {
                    handTotal += 11;
                    handTotal += (ace.size()-1);
                }
                else{
                    handTotal += ace.size(); 
                    //for(std::vector<cards::card>::iterator i = ace.begin(); i != ace.end(); ++i){
                    //    if(handTotal < 11){
                    //        handTotal += 11;
                    //    }else{
                    //        handTotal += 1;
                    //    }
                    //}
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
