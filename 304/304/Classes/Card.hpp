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
#include <string>

using namespace std;

typedef enum {
    spades, hearts, diamonds, clubs
} Suit;

typedef enum {
    jack=30,nine=20,ace=11,ten=10,king=3,queen=2
} Rank;

class Card {

public:
    Card(Suit suit, Rank rank);
    Suit getSuit();
    string getSuitName();
    Rank getRank();
    int getValue();
    string getValueString();
    void toString();
    unsigned long getHash();
    
private:
    Suit _suit;
    Rank _rank;
    
    
};

#endif /* Card_hpp */
