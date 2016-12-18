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


Deck::~Deck() {
    
}
// random generator function:
void _shuffle(vector<Card> &a) {
    size_t n = a.size();
    if (n <= 1){
        return;
    }
    
    for (int i = 0; i < n - 1; i ++) {
    
        int j = arc4random_uniform(uint32_t (n - 1)) + 1;
        
        if (i == j) {
            continue;
        }
        swap(a[i], a[j]);
    }
}

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
    
}

void Deck::shuffle(void) {
    _shuffle(_cards);
}

void Deck::printCards() {
    
    size_t size = _cards.size();
    for (int i=0;i<size;i++){
        Card c = _cards[i];
        c.toString();
    }
}

vector<Card> Deck::draw(int numberOfCards) {
    
    size_t size = _cards.size();
    if (size == 0 || size < numberOfCards) {
        return vector<Card>();
    }
    
    vector<Card> cards;
    for (int i=0;i<numberOfCards;i++){
        Card c = _cards[i];
        cards.push_back(c);
    }
    
    _cards.erase(_cards.begin(), _cards.begin() + numberOfCards);
    
    //std::cout << "Cards vector contains:" << _cards.size() << endl;
    return cards;
    
}

void Deck::toString() {
    std::cout << "Card count in the deck " << _cards.size() << "\n"<< endl;
}
