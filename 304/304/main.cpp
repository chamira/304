//
//  main.cpp
//  304
//
//  Created by Chamira Fernando on 04/12/2016.
//  Copyright © 2016 Chamira Fernando. All rights reserved.
//

#include <iostream>
#include "Deck.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "304 game!\n\n";
    
    Deck deck;
    deck.prepare();
    deck.shuffle();
    deck.printCards();
    return 0;
}
