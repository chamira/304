//
//  main.cpp
//  304
//
//  Created by Chamira Fernando on 04/12/2016.
//  Copyright © 2016 Chamira Fernando. All rights reserved.
//

#include <iostream>
#include "Deck.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Team.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "304 game!\n\n";
    
    Deck * deck = new Deck();
    

    Player * player1 = new Player("Chamira");
    Player * player2 = new Player("Nilu");
    
    Team * team1 = new Team("Suriyans", player1, player2);

    Player * player3 = new Player("Susiri");
    Player * player4 = new Player("Nadi");
    
    Team * team2 = new Team("Mayans", player3, player4);
    
    Game *game  = new Game(deck, team1, team2);
    
    game->start();
    game->toString();
    
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
