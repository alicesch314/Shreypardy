// ********************
//     Preamble
// ********************

#include "Player.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime> 

// ********************
//  Setters and Getters
// ********************

// Set/Get Player Name
std::string Player::getName(){
    return Name;
}
void Player::setName(std::string n){
    Name = n;
}
// Set/Get Player Sets
int Player::getScore(){
    return Score;
}
std::string Player::getPath(){
    return Path;
}
void Player::setScore(int increment){
    Score += increment;
}

// ********************
//       Functs
// ********************

// Displays Status of a Player 
void Player::Status() { // prints status of player
    std::cout << "Player: " << Name << std::endl;
    std::cout << "Score: " << Score << std::endl;
}

// ********************
//     Constructor
// ********************

Player::Player(std::string name) : Name(name), Score(0), Path() {
    Path = "/graphics/set1/Player" + name + ".png"; // path to player name card
}