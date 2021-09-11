// ********************
//     Preamble
// ********************

#ifndef QUESTION_H
#define QUESTION_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime> 

// ********************
//     Constructor
// ********************

static const std::string setnum = "set2"; // change to "set2"

// ********************
//     Constructor
// ********************

class Question {
private:
    int ID; // the ID of the question
    std::string V; // value of the card
    std::string PathFront; // front of question png path
    std::string PathBack; // back of question png path
    std::string ValuePath; // value of question path
    
public:
    Question(int id, std::string v);
    // Getters, setters not needed, characterisitcs of a card stay the same
    int getID();
    std::string getV();
    std::string getPathFront();
    std::string getPathBack();
    std::string getValuePath();
};

#endif // QUESTION_H