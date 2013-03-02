#include "class_blackjackAction.h"
#include <iostream>

namespace casino{

    blackjackAction::blackjackAction(controlType ct) : action(){
        if(ct == TERMINAL){
            bool valid = false;
            while(!valid){
                print();
                std::string input;
                std::cin >> input;
                if(input == "HIT" || input == "hit"){
                    blackjackAction::actionType = blackjackAction::HIT;
                    valid = true;
                }else if(input == "STAND" || input == "stand"){
                    blackjackAction::actionType = blackjackAction::STAND;
                    valid = true;
                // Ready to implement new features
                //}else if(input == "DOUBLE"){
                //    blackjackAction::actionType = blackjackAction::DOUBLE;
                //}else if(input == "SPLIT"){
                //    blackjackAction::actionType = blackjackAction::SPLIT;
                }else{
                    std::cout << "Unknown action" << std::endl;
                    valid = false;
                }
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
