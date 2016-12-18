//
//  Team.hpp
//  304
//
//  Created by Chamira Fernando on 17/12/2016.
//  Copyright © 2016 Chamira Fernando. All rights reserved.
//

#ifndef Team_hpp
#define Team_hpp

#include <stdio.h>
#include <string>
#include <stdio.h>
#include <iostream>

#include "Player.hpp"

using namespace std;

class Team {
public:
    Team(string name, Player * player1, Player * player2);
    ~Team();
    string getTeamName();
    Player * getPlayer1();
    Player * getPlayer2();
    void toString();
    
private:
    string _name;
    Player * _player1;
    Player * _player2;
};
#endif /* Team_hpp */
