#include "class_gambler.h"
#include "class_blackjackStrategy.h"
#include "class_blackjackAction.h"
#include <iostream>

using namespace std;
using namespace casino;

    gambler::gambler(string fname, string lname){
        
        firstName = fname;
        lastName = lname;

    }
    gambler::gambler(controlType ct){
        static int gamblerNr = 0;
        gamblerNr++;
        gamblerId = gamblerNr;

        strategy* s = new blackjackStrategy(ct);
        strategies.push_back(s);
    }
    void gambler::giveMoney(cash amount){
        wallet += amount;
    }
    cash gambler::placeBet(){
        // Cin amount?
        //string* s = new string();
        int i = 0;
        try{
        cout << "Place bet: ";
        cin >> i;
        }catch(int e){
            cout << endl << "Could not get that. Which amount will you bet? ";
            cin >> i;
        }
        // Remove money from wallet, and return the amount.
        // Cannot plage a bet larger than wallet?
        // This function is not done!!!!!

    }
    string gambler::name(){
        return firstName + " " + lastName;
    }
    
    bool gambler::ready(){
        return readyToPlay;
    }
    
    action* gambler::takeAction(gameState* g){
        //There will only be one strategy at this time. In future check for gametype
        action* a = strategies[0]->takeAction(g);
        return a;
    }
    void gambler::joinGame(game& g){
        readyToPlay = 1;
    }
