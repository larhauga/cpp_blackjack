#include <iostream>
#include "class_deck.h"
#include "class_blackjackGame.h"
#include <vector> //Testing vector. Clean up later
#include "class_game.h"
#include "gameTypes.h"

using namespace std;

int main(){
    cards::deck d = cards::deck(2);
    
    cout << "Stacked " << d.size() << " cards... comencing game" << endl;
    d.shuffle();
    cards::card c1 = d.deal();
    cout << c1.name() << endl;
    cards::card c2 = d.deal();
    cout << c2.name() << endl; 

    vector<cards::card> kort;
    kort.push_back(c1);
    kort.push_back(c2);

    cout << kort[0].getSuit() << endl;

    casino::blackjackGame* blackjack = new casino::blackjackGame(1);// = new casino::blackjackGame(1);
    //blackjack.start();
    //cards::card c3 = blackjack.deck.deal();
    //cout << c3.name();

    casino::game* game = new casino::game(casino::gameType[]);
}
