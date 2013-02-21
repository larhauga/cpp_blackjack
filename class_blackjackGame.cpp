#include <vector> // Used in hands
#include "class_deck.h"
#include "class_card.h"
#include "class_blackjackGame.h"


namespace casino{

    blackjackGame::blackjackGame(int players){
    
    };
        

    void blackjackGame::playRound(){
        // Do something
    }
    void blackjackGame::start(){
        // Setting up the deck
            // Everyday I'm shuffeling
        deck = cards::deck(2);
        deck.shuffle();
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
    }
    int handValue(std::vector<cards::card> c){
        int value = 0;
        value += cardPoints(c[0]);
        return value;
    }
}
