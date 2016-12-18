//
//  Game.hpp
//  304
//
//  Created by Chamira Fernando on 17/12/2016.
//  Copyright © 2016 Chamira Fernando. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Deck.hpp"
#include "Team.hpp"
#include "PlayingRound.hpp"
#include <vector>

class Game {

public:
    Game(Deck * deck, Team * team1, Team  * team2);
    ~Game();
    Deck * getDeck();
    Team * getTeam1();
    Team * getTeam2();
    void prepare();
    void start(short round);
    void setSeating();
    void firstDraw();
    void secondDraw();
    Player * dealer();
    unsigned short getRoundCounter();
    void toString();
    
private:
    unsigned int const kNumberOfRounds = 10;
    unsigned int const kNumberOfCardsPerDraw = 3;
    Deck * _deck;
    Team * _team1;
    Team * _team2;
    vector<Player *> _seating;
    Player * _dealer;
    short _rountCounter;
    void drawCards();
    Player * getPlayerAtSeatingPosition(unsigned short seatingPosition);
    unsigned short getValidatedSeatingPositing(unsigned short position);
};

#endif /* Game_hpp */
