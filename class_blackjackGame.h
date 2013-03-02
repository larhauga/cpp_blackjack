#ifndef CLASS_BLACKJACKGAME_H
#define CLASS_BLACKJACKGAME_H


#include "class_game.h"

// Included after new blackjackGame class functions
#include "class_card.h"
#include "class_deck.h"
#include <vector>

namespace casino{
  
  class blackjackGame : public game 
  {
    
    //Overridden from game
    virtual void playRound();
    
  public:
    
    //Constructor
    blackjackGame(int players=1);

    //Overridden from game
    virtual void start();

    //Not part of original design
    cards::deck* deck;
    int cardPoints(cards::card);
    int handValue(std::vector<cards::card>);
    
  };

}

#endif
