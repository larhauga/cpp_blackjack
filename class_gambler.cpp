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

        wallet = 0;
         // We are generous and give you 1000 chips to play for! Congrats!
        giveMoney(1000);
    }
    void gambler::giveMoney(cash amount){
        if(amount > 0){
            wallet += amount;
            //cout << "You got " << wallet << " cash in wallet." << endl;
        }else{
            cout << "You got " << wallet << " cash in wallet." << endl;
        }
    }
    cash gambler::placeBet(){
        float bet = 0;
        try{
        cout << "Place bet: ";
        cin >> bet;
        }catch(int e){
            cout << endl << "Could not get that. Which amount will you bet? ";
            cin >> bet;
        }
        if(bet <= wallet){
            wallet -= bet;
            return bet;
        }else{
            return 0;
        }

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
