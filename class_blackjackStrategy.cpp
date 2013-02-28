#include "class_blackjackStrategy.h"
#include "class_blackjackAction.h"

namespace casino{
    blackjackStrategy::blackjackStrategy(controlType ct) : strategy(){
       // Nowhere to initialize the controlType. Missing setters to base or local variable 
    }
    action* blackjackStrategy::takeAction(gameState* g){
        g->print();
        action* a = new blackjackAction(TERMINAL);
        return a;
    }
}
