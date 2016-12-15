//
//  Card.cpp
//  304
//
//  Created by Chamira Fernando on 04/12/2016.
//  Copyright © 2016 Chamira Fernando. All rights reserved.
//

#include "Card.hpp"
#include <iostream>

Card::Card(Suit suit, Rank rank) {
 
    _suit = suit;
    _rank = rank;
    
}

Suit Card::getSuit() {
    return _suit;
}

string Card::getSuitName() {
    
    string s = "";
    
    switch (_suit) {
        case hearts:
            s = "Hearts";
            break;
        case spades:
            s = "Spades";
            break;
        case diamonds:
            s = "Diamonds";
            break;
        case clubs:
            s = "Clubs";
            break;
        default:
            break;
    }
    
    return s;
    
}

Rank Card::getRank() {
    return _rank;
}

int Card::getValue() {
    //easiest... c++ its not easy to fetch value from enum
    int v = 0;
    switch (_rank) {
        case jack:
            v = 30;
            break;
        case nine:
            v = 20;
            break;
        case ace:
            v = 11;
            break;
        case ten:
            v = 10;
            break;
        case king:
            v = 3;
            break;
        case queen:
            v = 2;
            break;
        default:
            break;
    }
    
    return v;
    
}

string Card::getValueString() {
    
    string s = "";
    switch (_rank) {
        case jack:
            s = "Jack(30)";
            break;
        case nine:
            s = "9(20)";
            break;
        case ace:
            s ="Ace(11)";
            break;
        case ten:
            s = "Ten(10)";
            break;
        case king:
            s = "King(3)";
            break;
        case queen:
            s = "Queen(2)";
            break;
        default:
            break;
    }
    
    return s;
    
}

void Card::toString() {
    std::cout << "Card:" << getSuitName() << " Rank:" << getValueString() << std::endl;
}
