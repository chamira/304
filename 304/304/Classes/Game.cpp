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
    
    setSeating();
    
}

Game::~Game() {
    
    delete _deck;
    delete _team1;
    delete _team2;
    delete _dealer;
    
    _deck = NULL;
    _team1 = NULL;
    _team2 = NULL;
    _dealer = NULL;
    
}

void Game::prepare() {

    _deck->prepare();
    _deck->shuffle();
    
}

void Game::setSeating() {
    
    _seating.push_back(_team1->getPlayer1());
    _seating.push_back(_team2->getPlayer1());
    _seating.push_back(_team1->getPlayer2());
    _seating.push_back(_team2->getPlayer2());

}

void Game::start(short round) {
    if (round <= 0) {
        cout << "Round value must be greater than 0\n";
        return;
    }
    _rountCounter = round;
    prepare();
    firstDraw();
}

void Game::firstDraw() {
    drawCards();
}

void Game::secondDraw() {
    drawCards();
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

Player * Game::dealer() {
    return _dealer;
}

unsigned short Game::getRoundCounter() {
    return _rountCounter;
}

void Game::toString() {
    _team1->toString();
    _team2->toString();
}


//Private
void Game::drawCards() {
    
    unsigned short dealerSeatingPosition = getValidatedSeatingPositing(_rountCounter % 4);
    
    _dealer = getPlayerAtSeatingPosition(dealerSeatingPosition);
    
    unsigned short _1st = getValidatedSeatingPositing(dealerSeatingPosition + 1);
    Player * p1 = getPlayerAtSeatingPosition(_1st);
    
    unsigned short _2nd = getValidatedSeatingPositing(_1st + 1);
    Player * p2 = getPlayerAtSeatingPosition(_2nd);
    
    unsigned short _3rd = getValidatedSeatingPositing(_2nd + 1);
    Player * p3 = getPlayerAtSeatingPosition(_3rd);
    
    Player * p4 = _dealer;
    
    vector<Card> d1 = _deck->draw(kNumberOfCardsPerDraw);
    
    p1->addToHand(d1);
    
    vector<Card> d2 = _deck->draw(kNumberOfCardsPerDraw);
    p2->addToHand(d2);
    
    vector<Card> d3 = _deck->draw(kNumberOfCardsPerDraw);
    p3->addToHand(d3);
    
    vector<Card> d4 = _deck->draw(kNumberOfCardsPerDraw);
    p4->addToHand(d4);
    
    p1->toString();
    p2->toString();
    p3->toString();
    p4->toString();
    
}

unsigned short Game::getValidatedSeatingPositing(unsigned short position) {
    if (position == 0) {
        return 4;
    } else  if (position > 4) {
        return 1;
    }
    return position;
}

Player * Game::getPlayerAtSeatingPosition(unsigned short seatingPosition) {
    return _seating[seatingPosition-1];
}
