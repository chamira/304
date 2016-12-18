//
//  Team.cpp
//  304
//
//  Created by Chamira Fernando on 17/12/2016.
//  Copyright © 2016 Chamira Fernando. All rights reserved.
//

#include "Team.hpp"

Team::Team(string name, Player * player1, Player * player2) {
    _name = name;
    _player1 = player1;
    _player2 = player2;
}

Team::~Team() {
    delete _player1;
    delete _player2;
    _player1 = NULL;
    _player2 = NULL;
}

string Team::getTeamName() {
    return  _name;
}

Player * Team::getPlayer1() {
    return _player1;
}

Player * Team::getPlayer2() {
    return _player2;
}

void Team::toString() {
    std::cout << "Team: " << _name << " Player1: " << _player1->getName() << " Player2: " << _player2->getName() << endl;
}

