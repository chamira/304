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
#include "Brain.hpp"


struct Bid {
	short value;
	Card * trump;
};


using namespace std;

class Team;

class Player  {
    
public:
    Player(string name, unsigned short seatingPosition);
    ~Player();
    string getName();
    void addToHand(Card * card);
    void addToHand(vector<Card*> cards);
    vector<Card *> getHand();
    unsigned short getSeatingPosition();
    Card * getCardWithCode(string cardCode);
	void setPartner(Player *player);
	Player * getPartner();
	void setTeam(Team *team);
	Team * getTeam();
	void setBid(Bid bid);
	Bid getBid();
    void toString();

private:
    string _name;
    vector<Card *> _hand;
    unsigned short _seatingPosition;
	Player * _partner;
	Team * _team;
	Brain _brain;
	Bid _bid;
    
};
#endif /* Player_hpp */
