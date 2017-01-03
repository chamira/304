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
    //_deck->printCards();
    
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
    _roundCounter = round;
    _playingPosition = 1;
    
    prepare();
    setPlayingSequence();
    firstDraw();
    //secondDraw();
    _deck->toString();
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

Player * Game::getDealer() {
    return _dealer;
}

unsigned short Game::getRoundCounter() {
    return _roundCounter;
}

void Game::setBidValue(Player * player, Card * trump, BidValue value) {
    _bidder = player;
    _trump = trump;
    _bidValue = value;
}

Player * Game::getCurrentPlayer() {
    return _playingSequence[_playingPosition-1];
}

void Game::toString() {
    _team1->toString();
    _team2->toString();
}


//Private

void Game::setPlayingSequence() {
    
    unsigned short dealerSeatingPosition = getValidatedSeatingPositing(_roundCounter % 4);
    
    _dealer = getPlayerAtSeatingPosition(dealerSeatingPosition);
    
    unsigned short _1st = getValidatedSeatingPositing(dealerSeatingPosition + 1);
    Player * p1 = getPlayerAtSeatingPosition(_1st);
    
    unsigned short _2nd = getValidatedSeatingPositing(_1st + 1);
    Player * p2 = getPlayerAtSeatingPosition(_2nd);
    
    unsigned short _3rd = getValidatedSeatingPositing(_2nd + 1);
    Player * p3 = getPlayerAtSeatingPosition(_3rd);
    
    Player * p4 = _dealer;
    
    _playingSequence.push_back(p1);
    _playingSequence.push_back(p2);
    _playingSequence.push_back(p3);
    _playingSequence.push_back(p4);
    
}

void Game::drawCards() {
    
    Player * p1 = _playingSequence[0];
    Player * p2 = _playingSequence[1];
    Player * p3 = _playingSequence[2];
    Player * p4 = _playingSequence[3];
    
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
