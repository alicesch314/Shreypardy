// ********************
//     Preamble
// ********************

#ifndef GAME_H
#define GAME_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime> 

#include "Player.h"
#include "Question.h"

// ********************
//       Class
// ********************

class Game{
private:
    int Nop; // number of players
    std::vector<Player> Players; // players in the game
    std::vector<Question> Deck; // all questions in game
    std::vector<Question> Questions; // questions played in this game

public:
    Game();
    // Setters and Getters
    void setNop(int nop);
    int getNop();
    std::vector<Player> getPlayers();
    std::vector<Question> getQuestions();

    // Initializing Game 
    //Step (1) initializes nop
    void initNop();
    // Step (2) initializes players
    void initPlayers();
    // Step (3) initializes deck of cards playing from
    void initDeck();
    // Step (4) initialize questions
    void initQuestions();
    // Step (4) End of Game
    void gameOver();
};

#endif // GAME_H