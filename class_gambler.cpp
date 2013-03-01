#include "class_gambler.h"
#include "class_blackjackStrategy.h"
#include "class_blackjackAction.h"
#include <iostream>
#include <sstream>

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
        cash bet = 0;
        string s = "";
        cout << "Place bet: ";
        cin >> s;
        
        stringstream str(s);
        stringstream(s) >> bet;

        if(wallet == 0){
            return -1;
        }

        if(bet <= wallet){
            wallet -= bet;
            return bet;
        }else if(bet > wallet){
            cout << "You do not have that much cash. You only have " << wallet << endl;
        }else{
            cout << "Not a valid number" << endl;
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
