#include "class_blackjackGame.h"
#include "class_game.h"

using namespace std;

int main(){

    // Starting a new game
    casino::game* game;
    
    // Lets play jackblackt!
    game = new casino::blackjackGame();
    game->start();

    // Cleaning up
    delete game;
}
