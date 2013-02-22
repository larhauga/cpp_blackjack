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
            // Everyday I'm shuffeling
        deck = cards::deck(2);
        deck.shuffle();

        std::vector<cards::card> v;

        v.push_back(deck.deal());
        v.push_back(deck.deal());
        v.push_back(deck.deal());
        v.push_back(deck.deal());

        std::cout << "Rank: " << v[0].getRank() << " Points: " << cardPoints(v[0]) << std::endl<<std::endl;
        std::cout << "Rank: " << v[1].getRank() << " Points: " << cardPoints(v[1]) << std::endl<<std::endl; 
        std::cout << "Rank: " << v[2].getRank() << " Points: " << cardPoints(v[2]) << std::endl<<std::endl;
        std::cout << "Rank: " << v[3].getRank() << " Points: " << cardPoints(v[3]) << std::endl<<std::endl;

        std::cout << handValue(v) << std::endl;
        playRound();
        // while playing some rounds m'kay
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
    int blackjackGame::handValue(std::vector<cards::card> c){
        int value = 0;
        value += blackjackGame::cardPoints(c[0]);
        return value;
    }
}
