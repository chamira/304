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
    spades=1, hearts=2, diamonds=3, clubs=4
} Suit;

typedef enum {
    jack=30,nine=20,ace=11,ten=10,king=3,queen=2
} Rank;

class Card {

public:
    Card(Suit suit, Rank rank);
	~Card();
    Suit getSuit();
    string getSuitName();
    Rank getRank();
    int getValue();
    string getValueString();
    unsigned long getHash();
    string getCode();
    void toString();

private:
    Suit _suit;
    Rank _rank;
    
};

#endif /* Card_hpp */
