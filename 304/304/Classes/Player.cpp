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
#include <algorithm>

template <typename T>
void remove(std::vector<T>& vec, size_t pos) {
    typename std::vector<T>::iterator it = vec.begin();
    std::advance(it, pos);
    vec.erase(it);
}

Player::Player(string name, unsigned short seatingPosition) {
    _name = name;
    _seatingPosition = seatingPosition;
}

Player::~Player() {
    
}

string Player::getName() {
    return _name;
}

void Player::addToHand(Card *card) {
    _hand.push_back(card);
}

void Player::addToHand(vector<Card*> cards) {
    for (short i=0;i<cards.size();i++) {
        Card *c = cards[i];
        addToHand(c);
    }
}

vector<Card*> Player::getHand() {
    return  _hand;
}

unsigned short Player::getSeatingPosition() {
    return _seatingPosition;
}

Card * Player::getCardWithCode(string cardCode) {
 
    Card *c = nullptr;
    
    size_t size = _hand.size();
    
    transform(cardCode.begin(), cardCode.end(), cardCode.begin(), ::toupper);
    
    short index = -1;
    for (short i=0;i<size;i++){
        Card *card = _hand[i];
        string code = card->getCode();
        if (code == cardCode) {
            c = card;
            index = i;
            break;
        }
    }
    
    if (c != nullptr && index >= 0) {
        remove(_hand,index);
    }
	
    return c;
    
}

void Player::setPartner(Player *player) {
	_partner = player;
}

Player * Player::getPartner() {
	return _partner;
}

void Player::setTeam(Team *team) {
	_team = team;
}

Team * Player::getTeam() {
	return _team;
}

void Player::setBid(Bid bid) {
	_bid = bid;
}

Bid Player::getBid() {
	return _bid;
}

void Player::toString() {
    
    cout << "Player: " << _name  << " Sitting at " << getSeatingPosition();
    
    if (_hand.size() > 0) {
        cout << " **Hand:" ;
        
        string s = "";
        for (int i=0;i<_hand.size();i++){
            Card * c = _hand[i];
            s = s + " " + c->getSuitName() + " " + c->getValueString() + " code: " + c->getCode() + " " + to_string(c->getHash());
        }
        cout << s << endl;
    } else {
        cout << endl;
    }
    
}
