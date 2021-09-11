// ********************
//     Preamble
// ********************

#include "Question.h"
#include "AllQuestions.cpp"

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

//Set/Get Colour
int Question::getID(){
    return ID;
}
std::string Question::getV(){
    return V;
}
std::string Question::getPathFront(){
    return PathFront;
}
std::string Question::getPathBack(){
    return PathBack;
}
std::string Question::getValuePath(){
    return ValuePath;
}

// ********************
//     Constructor
// ********************

Question::Question(int id, std::string v) :
    ID(id), V(v), PathFront(), PathBack(), ValuePath() {
    PathFront = "/graphics/" + setnum + "/Cards/QuestionFront/QuestionFront" + std::to_string(id % 5) + ".png"; // path to png of front of question 
    PathBack = "/graphics/" + setnum + "/Cards/QuestionBack/QuestionBack" + std::to_string(id) + ".png"; // path to png of back of question 
    ValuePath = "/graphics/" + setnum + "/Cards/Values/Value" + v + ".png"; // path to value of question (number of shots to take)
}