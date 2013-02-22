#include "class_blackjackGame.h"
#include "class_game.h"

using namespace std;

int main(){

    // Starting a new game
    casino::game* game;
    
    // Lets play jackblack!
    game = new casino::blackjackGame();
    game->start();
}
