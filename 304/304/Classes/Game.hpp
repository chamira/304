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
    void start();
    void toString();
    
private:
    Deck * _deck;
    Team * _team1;
    Team * _team2;
    unsigned int const kNumberOfRounds = 10;
    vector<PlayingRound> _rounds;
    
};

#endif /* Game_hpp */
