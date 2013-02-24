#include "class_blackjackState.h"
#include <vector>
#include <iostream> // For the print method
#include "class_blackjackGame.h"

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
    void blackjackState::print(){
        // Printing helping text
        std::cout << "Player hand as following: " << std::endl;

        // Printing the players hand...
        for(int i = 0; i < cardsDealt[ourHero].size(); i++){
            std::cout << cardsDealt[ourHero][i].name() << std::endl;
        }

        // Printing the dealers hand
        std::cout << "The dealer shows one card: " << cardsDealt[dealer][0].name() << std::endl;
    }
}
