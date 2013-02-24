#include "class_blackjackState.h"
#include <vector>

namespace casino{

    blackjackState::blackjackState(std::vector<std::vector<cards::card> > cardv, int iHero, int iDealer) : gameState(){
        ourHero = iHero;
        dealer = iDealer;
        cardsDealt = cardv;
    }

    std::vector<cards::card> blackjackState::dealersCards(){
        return cardsDealt[dealer];
    }
    std::vector<cards::card> blackjackState::myCards(){
        return cardsDealt[ourHero];
    }

    std::vector<cards::card> blackjackState::cardsI(int i){
        return cardsDealt[i];
    }
    int blackjackState::getOurHero(){
        return ourHero;
    }
    int blackjackState::getDealer(){
        return dealer;
    }
    void print(){
        
    }
}
