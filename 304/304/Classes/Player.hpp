//
//  Player.hpp
//  304
//
//  Created by Chamira Fernando on 17/12/2016.
//  Copyright © 2016 Chamira Fernando. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "Card.hpp"

using namespace std;

class Player  {
    
public:
    Player(string name);
    ~Player();
    string getName();
    void addToHand(Card card);
    void addToHand(vector<Card> cards);
    vector<Card> getHand();
    
    void toString();
    
private:
    string _name;
    vector<Card> _hand;
    
};
#endif /* Player_hpp */
