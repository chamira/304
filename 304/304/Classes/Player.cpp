//
//  Player.cpp
//  304
//
//  Created by Chamira Fernando on 17/12/2016.
//  Copyright © 2016 Chamira Fernando. All rights reserved.
//

#include "Player.hpp"
#include <iostream>
#include <string>

Player::Player(string name, unsigned short seatingPosition) {
    _name = name;
    _seatingPosition = seatingPosition;
}

Player::~Player() {
    
}

string Player::getName() {
    return _name;
}

void Player::addToHand(Card card) {
    _hand.push_back(card);
}

void Player::addToHand(vector<Card> cards) {
    for (int i=0;i<cards.size();i++) {
        Card c = cards[i];
        addToHand(c);
    }
}

vector<Card> Player::getHand() {
    return  _hand;
}

unsigned short Player::getSeatingPosition() {
    return _seatingPosition;
}

void Player::toString() {
    
    cout << "Player: " << _name ;
    
    if (_hand.size() > 0) {
        cout << " **Hand:" ;
        
        string s = "";
        for (int i=0;i<_hand.size();i++){
            Card c = _hand[i];
            s = s + " " + c.getSuitName() + " " + c.getValueString();
        }
        cout << s << endl;
    } else {
        cout << endl;
    }
    
}
