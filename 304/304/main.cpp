//
//  main.cpp
//  304
//
//  Created by Chamira Fernando on 04/12/2016.
//  Copyright © 2016 Chamira Fernando. All rights reserved.
//

#include <iostream>
#include <string>
#include "Deck.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Team.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "304 game!\n\n";
    
    Deck * deck = new Deck();
    
    Player * player1 = new Player("Chamira",1);
    Player * player2 = new Player("Nilu",2);
    
    Team * team1 = new Team("Suriyans", player1, player2);

    Player * player3 = new Player("Susiri",3);
    Player * player4 = new Player("Nadi",4);
    
    Team * team2 = new Team("Mayans", player3, player4);
    
    Game *game  = new Game(deck, team1, team2);
    
    game->start(1);
    game->toString();

    Player *currentPlayer = game->getCurrentPlayer();
	
	short bidValues [8] = { 50, 60, 70, 80, 90, 100, 110, 120 };
	
    short bid = 0;
	std::string cardCode;
	bool pass = false;
	
	cout<< "Current player";
	currentPlayer->toString();
	cout << endl;
	while (pass == false) {
		
		std::cout << "Bid value? ";
		std::cin >> bid;
		for (short i = 0; i < 8; i++){
			short v = bidValues[i];
			if (v == bid) {
				pass = true;
				break;
			}
		}
	}
	
	Card *card = nullptr;
	
	while (card == nullptr){
		std::cout << "Card? ";
		cin >> cardCode;
		card = currentPlayer->getCardWithCode(cardCode);
		
	}
	
    
    if (card != nullptr) {
        cout << "trump ";
		cout << card->getSuitName() << "\n";
    } else {
        cout << "card is null";
    }
    
    /*deck.prepare();
    deck.shuffle();
    deck.printCards();
    std::cout << "\n\n";
    deck.shuffle();
    deck.printCards();
    std::cout << "\n\n";
    */
    
    return 0;
}
