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

Card::~Card() {
	cout << "Dealloc card " << getSuitName() << " " << getRank() << "\n";
}

Suit Card::getSuit() {
    return _suit;
}

Rank Card::getRank() {
	return _rank;
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
			s = "nothing";
            break;
    }
	
    return s;
    
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

unsigned long Card::getHash() {
    
    unsigned long s = 0;
    
    switch (_suit) {
        case hearts:
            s = 100000;
            break;
        case spades:
            s = 200000;
            break;
        case diamonds:
            s = 300000;
            break;
        case clubs:
            s = 400000;
            break;
        default:
            break;
    }
    
    switch (_rank) {
        case jack:
            s += 1;
            break;
        case nine:
            s += 2;
            break;
        case ace:
            s += 3;
            break;
        case ten:
            s += 4;
            break;
        case king:
            s += 5;
            break;
        case queen:
            s += 6;
            break;
        default:
            break;
    }
    
    return s;
    
}

string Card::getCode() {
    
    string s = "";
    
    switch (_suit) {
        case hearts:
            s = "H";
            break;
        case spades:
            s = "S";
            break;
        case diamonds:
            s = "D";
            break;
        case clubs:
            s = "C";
            break;
        default:
            break;
    }
    
    switch (_rank) {
        case jack:
            s = s + "J";
            break;
        case nine:
            s = s + "9";
            break;
        case ace:
            s = s + "A";
            break;
        case ten:
            s = s + "10";
            break;
        case king:
            s = s + "K";
            break;
        case queen:
            s = s + "Q";
            break;
        default:
            break;
    }
    
    return s;
}

void Card::toString() {
    std::cout << "Card:" << this->getSuitName() << " Rank:" << this->getValueString() << " hash:"<< this->getHash() << std::endl;
}
