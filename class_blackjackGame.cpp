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
    }
    void blackjackGame::start(){
        // Setting up the deck
        deck = cards::deck(2);

        // Everyday I'm shuffeling
        deck.shuffle();

        std::vector<cards::card> v;

        //v.push_back(deck.deal());
        //v.push_back(deck.deal());
        //v.push_back(deck.deal());
        //v.push_back(deck.deal());
        v.push_back(cards::card((cards::t_suit)cards::SPADES, (cards::t_rank)'A'));
        v.push_back(cards::card((cards::t_suit)cards::HEARTS, (cards::t_rank)'A'));
        v.push_back(cards::card((cards::t_suit)cards::CLUBS, (cards::t_rank)'A'));
        v.push_back(cards::card((cards::t_suit)cards::DIAMONDS, (cards::t_rank)'A'));

        std::cout << "Rank: " << v[0].getRank() << " Points: " << cardPoints(v[0]) << std::endl<<std::endl;
        std::cout << "Rank: " << v[1].getRank() << " Points: " << cardPoints(v[1]) << std::endl<<std::endl; 
        std::cout << "Rank: " << v[2].getRank() << " Points: " << cardPoints(v[2]) << std::endl<<std::endl;
        std::cout << "Rank: " << v[3].getRank() << " Points: " << cardPoints(v[3]) << std::endl<<std::endl;

        std::cout << handValue(v) << std::endl;
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
            for(std::vector<cards::card>::iterator i = ace.begin(); i != ace.end(); ++i){
                if(handTotal < 11){
                    handTotal += 11;
                }else{
                    handTotal += 1;
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
