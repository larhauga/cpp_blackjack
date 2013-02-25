#include "class_blackjackAction.h"
#include <iostream>

namespace casino{

    blackjackAction::blackjackAction(controlType ct) : action(){
        std::string input;
        std::cin >> input;
        if(input == "HIT"){
            blackjackAction::actionType = blackjackAction::HIT;
        }else if(input == "STAND"){
            blackjackAction::actionType = blackjackAction::STAND;
        }else{
            std::cout << "Unknown action. HIT or STAND" << std::endl;
        }
    }

    blackjackAction::atype blackjackAction::getAtype(){
        return actionType;
    }
    void blackjackAction::print(){
        
    }
}
