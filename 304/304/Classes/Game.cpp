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
	
	short value = bid->value;
	
	if (value <= _bidValue) {
		cout << "Illegal bid value of " << value << endl;
		return;
	}

	if (_bidder != NULL) {
		_bidder->addToHand(_trump);
	}
	
	_bidValue = value;
	
    _bidder = player;
	
	Card *trump = bid->trump;
	_trump = trump;

	cout << "Bid by -> " << _bidder->getName() << " value ->" << _bidValue << " trump " << _trump->getSuitName() << " " << endl;
	
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

// -1 = yet to bid, 0 = no bid , 1 = ask parter, 2 = not enough cards to bid (i.e q,k)
bool isSignalValue(short value) {
	const short sCount = 4;
	short bidValues [sCount] = { -1, 0, 1, 2 };
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

Bid Game::getBidFromPlayer(Player * player) {
	
	short bid = -1;
	std::string cardCode;
	bool pass = false;
	
	cout<< "Current Bidder: ";
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
	
	Bid b;
	b.value = bid;
	
	if (isSignalValue(bid) == false) {
		Card *card = nullptr;
		
		while (card == nullptr){
			std::cout << "Card? ";
			cin >> cardCode;
			card = player->getCardWithCode(cardCode);
			b.trump = card;
		}
	}
	
	return b;
	
}

Player * Game::getNextPlayerToBid(Player *bidPlayer ,short currentBidValue) {
	
	Player *player = nullptr;
	
	if (currentBidValue == -1) {
		player = getCurrentPlayer(); // no bid yet
	} else if (currentBidValue == 1) { //pass to partner
		Player *currentPlayer = getCurrentPlayer();
		player = currentPlayer->getPartner();
	} else if (currentBidValue == 2){ // partner is not able to bid either
		player = nullptr;
	} else if (currentBidValue == 120) {
		player = bidPlayer;
	} else {
		
		short position = bidPlayer->getSeatingPosition();
		if (position == 4) {
			position = 1;
		} else {
			position++;
		}
		
		player = getPlayerAtSeatingPosition(position);
		
	}
	
	return player;
}

void Game::startBidding() {
	
	bool isBiddingDone = false;
	
	Player *currentPlayer = getCurrentPlayer();
	
	Bid bid;
	Player *nextPlayer = currentPlayer;
	
	while (isBiddingDone == false) {
		
		bid = getBidFromPlayer(nextPlayer);
		setBidValue(nextPlayer, &bid);
		Player *player = getNextPlayerToBid(nextPlayer, bid.value);
		
		if (player == nullptr) {
			isBiddingDone = true;
			cout << "Partner is not able to bid either end of round " << _roundCounter << endl;
			break;
		} else if (player == currentPlayer) {
		
			isBiddingDone = true;
			
		} else {
			if (player == nextPlayer->getPartner()) {
				cout << "Ask partner to bid " <<endl;
			}
			isBiddingDone = false;
			nextPlayer = player;
		}
	}
	
	secondDraw();
	
}
