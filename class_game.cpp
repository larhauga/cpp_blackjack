#include "class_game.h"

namespace casino{

    game::game(gameType type, int players){
         t = type;
         //Make gamblers
    }
    gameType game::getType(){
        return t;
    }
}
