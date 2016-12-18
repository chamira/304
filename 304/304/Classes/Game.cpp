//
//  Game.cpp
//  304
//
//  Created by Chamira Fernando on 17/12/2016.
//  Copyright © 2016 Chamira Fernando. All rights reserved.
//

#include "Game.hpp"

Game::Game(Deck * deck, Team * team1, Team  * team2) {
    _deck = deck;
    _team1 = team1;
    _team2 = team2;
}

Game::~Game() {
    delete _deck;
    delete _team1;
    delete _team2;
    _deck = NULL;
    _team1 = NULL;
    _team2 = NULL;
}

void Game::prepare() {

    _deck->prepare();
    _deck->shuffle();
    
}

void Game::start() {

    prepare();
    
}

Deck * Game::getDeck() {
    return _deck;
}

Team * Game::getTeam1() {
    return _team1;
}

Team * Game::getTeam2() {
    return _team2;
}

void Game::toString() {
    
    _team1->toString();
    _team2->toString();
}
