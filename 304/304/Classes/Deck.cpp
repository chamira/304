//
//  Deck.cpp
//  304
//
//  Created by Chamira Fernando on 04/12/2016.
//  Copyright © 2016 Chamira Fernando. All rights reserved.
//

#include "Deck.hpp"
#include "Card.hpp"
#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstdlib>      // std::rand, std::srand

// random generator function:
int myrandom (int i) { return std::rand()%i;}

void Deck::addCards(Suit suit) {

    Card cardJack(suit, jack);
    Card cardNine(suit, nine);
    Card cardAce(suit, ace);
    Card cardTen(suit, ten);
    Card cardKing(suit, king);
    Card cardQueen(suit, queen);
    
    _cards.push_back(cardJack);
    _cards.push_back(cardNine);
    _cards.push_back(cardAce);
    _cards.push_back(cardTen);
    _cards.push_back(cardKing);
    _cards.push_back(cardQueen);
    
}

void Deck::prepare(void) {
    
    if (_cards.size() == kCardCount) {
        return;
    }
    
    addCards(hearts);
    addCards(spades);
    addCards(diamonds);
    addCards(clubs);
    
    std::cout << "Card count in the deck " << _cards.size() << "\n\n"<< endl;
    
}

void Deck::shuffle(void) {
    std::random_shuffle(_cards.begin(),_cards.end(), myrandom);
}

void Deck::printCards() {
    
    size_t size = _cards.size();
    for (int i=0;i<size;i++){
        Card c = _cards[i];
        c.toString();
    }
}
