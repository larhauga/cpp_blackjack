#include "class_card.h"

namespace cards{
    card::card(t_suit s, t_rank r){
        suit = s;
        rank = r;
    };
    std::string card::name(){
        return std::string(suit_name[card::suit] + card::rank);
    };

    t_suit card::getSuit(){
        return suit;
    };
    t_rank card::getRank(){
        return rank;
    }
}
