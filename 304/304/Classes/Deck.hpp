//
//  Deck.hpp
//  304
//
//  Created by Chamira Fernando on 04/12/2016.
//  Copyright © 2016 Chamira Fernando. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <vector>
#include "Card.hpp"

using namespace std;

class Deck {
public:
    ~Deck();
    void prepare();
    void shuffle();
    void printCards();
    vector<Card> draw(int numberOfCards);
    void toString();
    
private:
    int const kCardCount = 24;
    vector<Card> _cards;
    void addCards(Suit suit);
    
};
#endif /* Deck_hpp */

