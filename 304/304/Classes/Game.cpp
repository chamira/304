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
	
	startBidding();
	
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

void Game::setBidValue(Player * player, Bid * bid) {
    _bidder = player;
	
	Card *trump = bid->trump;
	_trump = trump;
	
	short value = bid->value;
    _bidValue = value;
	
	cout << "Final bid by -> " << _bidder->getName() << " value ->" << _bidValue << " trump " << _trump->getSuitName() << " " << endl;
	
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
    
    vector<Card *> d1 = _deck->draw(kNumberOfCardsPerDraw);
    p1->addToHand(d1);
    
    vector<Card*> d2 = _deck->draw(kNumberOfCardsPerDraw);
    p2->addToHand(d2);
    
    vector<Card*> d3 = _deck->draw(kNumberOfCardsPerDraw);
    p3->addToHand(d3);
    
    vector<Card*> d4 = _deck->draw(kNumberOfCardsPerDraw);
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

bool isValidBidValue(short value) {
	short bidValues [8] = { 50, 60, 70, 80, 90, 100, 110, 120 };
	bool pass = false;
	for (short i = 0; i < 8; i++){
		short v = bidValues[i];
		if (v == value) {
			pass = true;
			break;
		}
	}
	
	return pass;
}

// -1 = yet to bid, 0 = no bid , 1 = ask parter
bool isSignalValue(short value) {
	const short sCount = 3;
	short bidValues [sCount] = { -1, 0, 1 };
	bool pass = false;
	for (short i = 0; i < sCount; i++){
		short v = bidValues[i];
		if (v == value) {
			pass = true;
			break;
		}
	}
	
	return pass;

}

Bid * Game::getBidFromPlayer(Player * player) {
	
	short bid = -1;
	std::string cardCode;
	bool pass = false;
	
	cout<< "Current Bidder:";
	player->toString();
	cout << endl;
	
	while (pass == false) {
		
		std::cout << "Bid value? ";
		std::cin >> bid;
		
		if (isSignalValue(bid)) {
			break;
		} else {
			pass = isValidBidValue(bid);
		}
		
	}
	
	Bid *b = new Bid();
	b->value = bid;
	
	if (isSignalValue(bid) == false) {
		Card *card = nullptr;
		
		while (card == nullptr){
			std::cout << "Card? ";
			cin >> cardCode;
			card = player->getCardWithCode(cardCode);
			b->trump = card;
		}
	}
	
	return b;
	
}

void Game::startBidding() {
	
	Player *currentPlayer = getCurrentPlayer();
	Bid *bid = getBidFromPlayer(currentPlayer);
	
	if (bid->value == 120) {
		
		setBidValue(currentPlayer, bid);
		currentPlayer->toString();
	}
	
	
}
