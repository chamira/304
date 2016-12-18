//
//  Player.cpp
//  304
//
//  Created by Chamira Fernando on 17/12/2016.
//  Copyright © 2016 Chamira Fernando. All rights reserved.
//

#include "Player.hpp"
#include <iostream>

Player::Player(string name) {
    _name = name;
}

Player::~Player() {
}

string Player::getName() {
    return _name;
}

void Player::toString() {
    cout << "Player: " << _name << endl;
}
