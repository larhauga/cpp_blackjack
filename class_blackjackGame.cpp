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
        cards::card c = deck.deal();

        // Debug printline
        std::cout << c.getRank() << std::endl;
        // std::cout << cardPoints(c) << std::endl; // Reference to cardPoints at this points causes undefined reference. Outcommented waiting fix.
        playRound();
        // while playing some rounds m'kay
    }

    // This function is right now not a part of the class
    int cardPoints(cards::card c){
        for(int i = 0; i < cards::NUM_RANKS; i++){
            if(cards::ranks[i] == c.getRank()){
                if(i < 10){
                    return i+2;
                }
                else{
                    return -1;
                    //ikke ferdig
                }
            }
        }
        return 0;
    }
    int handValue(std::vector<cards::card> c){
        int value = 0;
        value += cardPoints(c[0]);
        return value;
    }
}
