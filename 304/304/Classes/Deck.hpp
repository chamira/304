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
    void prepare();
    void shuffle();
    
private:
    vector<Card> _cards;
    
};
#endif /* Deck_hpp */

