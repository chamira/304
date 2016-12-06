//
//  Card.hpp
//  304
//
//  Created by Chamira Fernando on 04/12/2016.
//  Copyright © 2016 Chamira Fernando. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <stdio.h>

enum Suit {
    spades, hearts, diamonds, clubs
};

enum Rank {
    jack=30,nine=20,ace=11,ten=10,king=3,queen=2
};

class Card {

public:
    Card(Suit suit, Rank rank);
    Suit getSuit();
    Rank getRank();
    int getValue();
    
private:
    Suit _suit;
    Rank _rank;
    
};

#endif /* Card_hpp */
