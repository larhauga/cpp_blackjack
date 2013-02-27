#include "class_gambler.h"

using namespace std;
using namespace casino;

    gambler::gambler(string fname, string lname){
        // Set gamlerNr eller gamblerId her
        firstName = fname;
        lastName = lname;
    }
    gambler::gambler(controlType ct){
    
    }
    void gambler::giveMoney(cash amount){
        wallet += amount;
    }
    cash gambler::placeBet(){
    
    }
    string gambler::name(){
        return firstName + " " + lastName;
    }
    
    bool gambler::ready(){
        return readyToPlay;
    }
    
    action* gambler::takeAction(gameState* g){
        
    }
    void gambler::joinGame(game& g){
        readyToPlay = 1;
    }
