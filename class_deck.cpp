#include <vector>
#include <algorithm>    // random shuffle http://www.cplusplus.com/reference/algorithm/random_shuffle/
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include "class_deck.h"
#include "class_card.h"

namespace cards{

    deck::deck(){
        for(int suitnum = 0; suitnum < NUM_SUITS; suitnum++){
           for(int ranknum = 0; ranknum < NUM_RANKS; ranknum++){
               cards.push_back(card((t_suit)suitnum, ranks[ranknum]));
           }
        }
    }
    deck::deck(int deckCount){
        for(int i = 0; i < deckCount; i++){
            for(int suitnum = 0; suitnum < NUM_SUITS; suitnum++){
                for(int ranknum = 0; ranknum < NUM_RANKS; ranknum++){
                    cards.push_back(card((t_suit)suitnum, ranks[ranknum]));
                }
            }
        }
    }

    void deck::shuffle(){
        //Using random_shuffle for shuffeling of vector with time as seed
        std::srand(unsigned(time(NULL)));
        std::random_shuffle(cards.begin(), cards.end());
    }
    card deck::deal(){
        //Creating card object to return, and removes the card
        card c(cards.back());
        cards.pop_back();
        return c;
    }

    int deck::size(){
        return cards.size();
    }
}
