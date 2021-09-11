// ********************
//     Preamble
// ********************

#include "Game.h"
#include "AllQuestions.cpp"

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime> 

// ********************
// Setters and Getters
// ********************

// Set/Get Nop
void Game::setNop(int nop){
    Nop = nop;
} 
int Game::getNop(){
    return Nop;
}

// Set/Get Players
std::vector<Player> Game::getPlayers(){
    return Players;
}
std::vector<Question> Game::getQuestions() {
    return Questions;
}

// ********************
//      Helpers
// ********************

// STEP (1) 
// Initializes the number of players
void Game::initNop(){
    std::cout << "Number of players?" << std::endl;
    std::cin >> Nop;
}

// STEP (2)
// Initializes the players in the players vect
void Game::initPlayers(){
    Players.reserve(Nop); // make vector size of nop

    // loop init nop number of players
    for (int i = 0; i < Nop; ++i){ 
        std::string name;
        std::cout << "Player " << i + 1 << " name?" << std::endl;
        std::cin >> name;
        // adding player to end of vect
        Players.push_back(Player(name)); 
    }
    // print out beginning of game
    if (Nop == 1){
        std::cout << "\nThe game has begun with 1 player, " << Players[0].getName();
        std::cout << "." << std::endl;
    } else {
        std::cout << "\nThe game has begun with " << Nop << " players, ";
        for (int i = 0; i < Nop; ++i){
            if (i == Nop - 1) {
            std::cout <<  "and " << Players[i].getName() << "." << std::endl;
            } else std::cout << Players[i].getName() << ", ";
        }
    }
}

// STEP (5) 
// Initializes the set o questions 
void Game::initDeck(){
    Deck.reserve(30);
    // loop to put all questions in the deck
    for (int i = 0; i < noq; ++i){
        std::string tempV(values[i]);
        Deck.__emplace_back(Question(i, tempV));
    }
    /*
    // Shuffles the order of cards in the deck
    srand((unsigned) time(0));
    int qNumber;
    // loop to shuffle all 30 cards
    for (int i = 0; i < noq; ++i){
        qNumber = i + (rand() % (noq - i));
        std::swap(Deck[i], Deck[qNumber]);
    }
    */
}

// STEP (4)
// Initializes questions in the game
void Game::initQuestions(){
    Questions.reserve(30);

    // loop init questions
    for (int i = 0; i < 30; ++i){
        Questions.push_back(Deck[Deck.size() - 1]); // add last card from Deck to Table
        Deck.pop_back(); // remove last element from Deck + resize();
    }
}

// ********************
//     Constructor
// ********************

Game::Game() : Nop(), Players(), Questions() {}