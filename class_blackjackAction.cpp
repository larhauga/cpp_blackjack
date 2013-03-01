#include "class_blackjackAction.h"
#include <iostream>

namespace casino{

    blackjackAction::blackjackAction(controlType ct) : action(){
        if(ct == TERMINAL){
            print();
            std::string input;
            std::cin >> input;
            if(input == "HIT"){
                blackjackAction::actionType = blackjackAction::HIT;
            }else if(input == "STAND"){
                blackjackAction::actionType = blackjackAction::STAND;
            // Ready to implement new features
            //}else if(input == "DOUBLE"){
            //    blackjackAction::actionType = blackjackAction::DOUBLE;
            //}else if(input == "SPLIT"){
            //    blackjackAction::actionType = blackjackAction::SPLIT;
            }else{
                std::cout << "Unknown action" << std::endl;
            }
        }else{

        }
    }

    blackjackAction::atype blackjackAction::getAtype(){
        return actionType;
    }
    void blackjackAction::print(){
        std::cout << "HIT or STAND: ";
    }
}
