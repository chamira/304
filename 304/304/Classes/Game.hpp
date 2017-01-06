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

struct Bid {
	short value;
	Card * trump;
};


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
    void setBidValue(Player * player, Bid * bid);
    void toString();

private:
    unsigned int const kNumberOfRounds = 10;
    unsigned int const kNumberOfCardsPerDraw = 3;
    Deck * _deck;
    Team * _team1;
    Team * _team2;
    Player *_bidder;
    Card *_trump;
    
    short _bidValue = 0;
    
    vector<Player *> _seating;
    vector<Player *> _playingSequence;
    Player * _dealer;
    short _roundCounter;
    short _playingPosition;
    void setPlayingSequence();
    void drawCards();
    Player * getPlayerAtSeatingPosition(unsigned short seatingPosition);
    unsigned short getValidatedSeatingPositing(unsigned short position);
	void startBidding();
	Bid getBidFromPlayer(Player * player);
	Player * getNextPlayerToBid(Player *bidPlayer, short currentBidValue);
	
};

#endif /* Game_hpp */
