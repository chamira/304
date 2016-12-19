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

typedef enum {
    fifty=50,sixty=60,seventy=70,eighty=80,ninety=90,hundred=100,oneten=110,onetwenty=130
}BidValue;

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
    Player * getDealer();
    Player * getCurrentPlayer();
    unsigned short getRoundCounter();
    void setBidValue(Player * player, Card * trump, BidValue value);
    void toString();
    
    
private:
    unsigned int const kNumberOfRounds = 10;
    unsigned int const kNumberOfCardsPerDraw = 3;
    Deck * _deck;
    Team * _team1;
    Team * _team2;
    Player *_bidder;
    Card *_trump;
    
    BidValue _bidValue;
    
    vector<Player *> _seating;
    vector<Player *> _playingSequence;
    Player * _dealer;
    short _rountCounter;
    short _playingPosition;
    void setPlayingSequence();
    void drawCards();
    Player * getPlayerAtSeatingPosition(unsigned short seatingPosition);
    unsigned short getValidatedSeatingPositing(unsigned short position);
};

#endif /* Game_hpp */
