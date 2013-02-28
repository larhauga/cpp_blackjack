#include "class_game.h"
#include <iostream>
#include <sstream>

using namespace std;
namespace casino{

    game::game(gameType type, int players){
        t = type;


        //Make gamblers
        for(int i = 0; i < players; i++){
            /*
            cout << "Name: ";
            string s = "";
                cin >> s; 
                
                getline(cin, s);
                for(int p = 0; p < s.length();p++){
                    if(s[i] == ' '){
                        cout << s.substr(0,i) << endl;
                        firstname.append(s.substr(0,i));
                        lastname.append(s.substr(i+1, s.length()-1));
                        break;
                    }
            */
                game::gamblers.push_back(gambler(TERMINAL));
                
        }
    }
    gameType game::getType(){
        return t;
    }
}
