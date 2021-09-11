// ********************
//     Preamble
// ********************

#ifndef PLAYER_H
#define PLAYER_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime> 

// ********************
//       Class
// ********************

class Player {
private:
    std::string Name; // stores username
    int Score; // score of player
    std::string Path;

public:
    Player(std::string name);
    // Setters and Getters
    void setName(std::string n);
    std::string getName();
    void setScore(int increment);
    std::string getPath();
    int getScore();
    // displays status of a player
    void Status();
};

#endif // PLAYER_H