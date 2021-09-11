// ********************
//     Preamble
// ********************

#include "RenderWindow.h"
#include "Entity.h"
#include  "Game.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// ********************
//        Main
// ********************

// setting x, y coordinates of qs
std::vector<Coords> setCoords(){
    // init array of coordinates 
    std::vector<Coords> qCoords;

    float tempX, tempY;
    // loop to set values
    for (int i = 0; i < 30; ++i){
        tempX = spaceX + ceil(i / 5) * (qWidth + spaceX);
        tempY = spaceY + headerHeight + (i % 5) * (qHeight + spaceY);
        qCoords.push_back(Coords(tempX, tempY));
    }
    return qCoords;
}

// setting x, y coordinates of player cards on screen
std::vector<Coords> setPlayerCoords(int nop){
    // init array of coordinates
    std::vector<Coords> pCoords;

    float tempX, tempY;
    int div;
    if (nop < 4) div = nop + 1;
    else div = 5;
    // loop to set values
    for (int i = 0; i < nop ; ++i){
        if (i < 4) {
            tempX =  (screenWidth / div) * (i + 1) - (qWidth / 2);
            tempY = 400;
        } else {
            tempX = (screenWidth / (nop - 3)) * ((i % 4 + 1) % (nop - 3)) - (qWidth / 2);
            tempY = 580;
        }
        pCoords.push_back(Coords(tempX, tempY));
    }
    return pCoords;
}


int main(int argv, char *args[]){
    // Error checking
    if (SDL_Init(SDL_INIT_VIDEO) > 0){
        std::cout << "SDL failed to init. Error: " << SDL_GetError() << std::endl;
    }
    if (!(IMG_Init(IMG_INIT_PNG))){
        std::cout << "IMG failed to init. Error: " << IMG_GetError() << std::endl;
    }
    
    // Game Init
    Game game;
    game.initNop();
    game.initPlayers();
    game.initDeck();
    game.initQuestions();
    std::vector<Coords> qCoords = setCoords();
    std::vector<Coords> pCoords = setPlayerCoords(game.getNop());

    // Window Init 
    RenderWindow window; // init window
    window.initWindow("SHREYPARDY! V.1", screenWidth, screenHeight); // rasterize window

    // Event Init
    SDL_Event event;

    // Background init
    std::string currPath = "/graphics/" + setnum + "/Background.png";
    SDL_Texture *t_background = window.initTexture(currPath.c_str());
    Entity e_background = Entity(Coords(0, 0), t_background, 1);

    // Header init
    Entity *e_Headers = (Entity*)malloc(sizeof(Entity) * 55); // entities
    Coords c_Header = Coords(0, 0); // coords

    for (int i = 0; i < 55; ++i){
        std::string currPath = "/graphics/" + setnum + "/Headers/Header" + std::to_string(i) + ".png";
        SDL_Texture * currHeader = window.initTexture(currPath.c_str());
        e_Headers[i] = Entity(c_Header, currHeader, 1);
    }

    // Board init (30 qs, 5 by 6)
    SDL_Texture *t_Questions[30]; // textures
    Entity *e_Questions = (Entity*)malloc(sizeof(Entity) * 30); // entities

    // Stores active questions that should appear on table
    std::string activeQuestions[30];

    for (int i = 0; i < 30; ++i){
        // finding q path
        SDL_Texture *currQuestion = window.initTexture((game.getQuestions()[29 - i].getPathFront()).c_str());
        // Adding texture to texture array
        t_Questions[i] = currQuestion;
        // adding platform entity for q
        e_Questions[i] = Entity(qCoords[i], currQuestion, 1);
        // activating questions on board
        activeQuestions[i] = "active";
    }    

    // Game Loop
    bool active = true; // true while game is active
    bool animated = false; // so the program doesnt suicide

    while (active){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT) active = false; // quit game
            else if (event.type == SDL_MOUSEBUTTONDOWN){
                int x_loc, y_loc;
                Uint32 buttons = SDL_GetMouseState(&x_loc, &y_loc); // store coords

                // finding q number
                x_loc = ceil((x_loc - spaceX) / (qWidth + spaceX));
                y_loc = ceil((y_loc - headerHeight) / (qHeight + spaceY));

                int qNum = (x_loc - 1) * 5 + y_loc - 1; // finding q number on table
                // deactivating card
                activeQuestions[qNum] = "inactive";

                // making card appear bigger
                float scale = 1.1;
                float tempX = qCoords[qNum].getX() - (qWidth * (scale - 1));
                float tempY = qCoords[qNum].getY() - (qHeight * (scale - 1));
                Coords tempCoords = Coords(tempX, tempY);

                // showing how many shots should be taken
                SDL_Texture *t_Value = window.initTexture(game.getQuestions()[qNum].getValuePath().c_str());
                Entity e_Value = Entity(tempCoords, t_Value, scale);
                // reshowing screen
                window.clear();
                window.render(e_background);
                window.render(e_Headers[27]);
                // render qs on table in loop
                for (int i = 0; i < 30; ++i){
                    if (i == qNum) window.render(e_Value);
                    else if (activeQuestions[i] == "active") window.render(e_Questions[i]); // rendering qs
                }
                window.display();
                SDL_Delay(1000);

                // show question on card
                SDL_Texture *t_Question = window.initTexture(game.getQuestions()[qNum].getPathBack().c_str());
                Entity e_Question = Entity(Coords(0, 0), t_Question, 1);
                window.render(e_Question);
                window.display();

                // if click, show scoring screen
                while (SDL_WaitEvent(&event)){
                    if (event.type == SDL_QUIT) active = false; // quit game
                    else if (event.type == SDL_MOUSEBUTTONDOWN){
                        int score = ((qNum % 5) + 1) * 100; // score player recieves
                        
                        // showing new screen asking player score
                        std::string currPath = "/graphics/" + setnum + "/Score.png";
                        SDL_Texture *t_Score = window.initTexture(currPath.c_str());
                        Entity e_Score = Entity(Coords(0, 0), t_Score, 1);
                        
                        // showing options of players
                        SDL_Texture *t_Players[game.getNop()];
                        Entity *e_Players = (Entity*)malloc(sizeof(Entity) * game.getNop()); // entities
                        // loop to init texture of player option cards
                        for (int i = 0; i < game.getNop(); ++i){
                            std::string currPath = "/graphics/" + setnum + "/Cards/Players/Player" + std::to_string(i + 1) + ".png";
                            SDL_Texture *currPlayer = window.initTexture(currPath.c_str());
                            //SDL_Texture *currPlayer = window.initTexture(game.getPlayers()[i].getPath().c_str());
                            t_Players[i] = currPlayer;
                            e_Players[i] = Entity(pCoords[i], currPlayer, 1);
                        }
                        // rednering and displaying
                        window.render(e_Score);
                        for (int i = 0; i < game.getNop(); ++i) window.render(e_Players[i]);
                        window.display();

                        // finding which player was clicked
                        while (SDL_WaitEvent(&event)){
                            if (event.type == SDL_QUIT) active = false; // quit game
                            else if (event.type == SDL_MOUSEBUTTONDOWN){
                                Uint32 buttons = SDL_GetMouseState(&x_loc, &y_loc); // store coords
                                // finding which player option was clicked
                                //tempX = (screenWidth / div) * ((i + 1) % div) - (qWidth / 2);
                                int pNum;
                                for (int i = 0; i < game.getNop(); ++i){
                                    if (x_loc < pCoords[i].getX() + qWidth && x_loc > pCoords[i].getX()){
                                        if (y_loc < pCoords[i].getY() + qHeight && y_loc > pCoords[i].getY()){
                                            pNum = i + 1;
                                            break;
                                        }
                                    }
                                }
                                // incrementing player score 
                                game.getPlayers()[pNum].setScore(score);
                                // making card appear bigger when clicked
                                tempX = pCoords[pNum - 1].getX() - (qWidth * (scale - 1));
                                tempY = pCoords[pNum - 1].getY() - (qHeight * (scale - 1)); 
                                
                                // rendering and displaying
                                Entity e_tempPlayer = Entity(Coords(tempX, tempY), t_Players[pNum - 1], scale);
                                window.render(e_Score);
                                for (int i = 0; i < game.getNop(); ++i){
                                    if (i != pNum - 1) window.render(e_Players[i]);
                                } 
                                window.render(e_tempPlayer);
                                window.display();
                                SDL_Delay(2000);
                                
                                animated = false;
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
        // check to see if all the cards have been clicked
         // displaying player scores
        for (int i = 0; i < game.getNop(); ++i){
            if (activeQuestions[i] == "active");
            else {
                
            }
        }
        SDL_Delay(1000);
        if (!animated){ // so that it only animates once and doesnt fucking crash
            for (int i = 0; i < 55; ++i){
                window.clear();
                window.render(e_background);
                for (int i = 0; i < 30; ++i){
                // displaying the questions on the board if they're active
                    if (activeQuestions[i] == "active") window.render(e_Questions[i]); // rendering qs
                }
                window.render(e_Headers[i]);
                window.display();
                SDL_Delay(20);
            }
            animated = true;
        } else { // if the animation has already been shown 
            window.clear();
            window.render(e_background);
            window.render(e_Headers[27]);
            // render qs on table in loop
            for (int i = 0; i < 30; ++i){
                // displaying the questions on the board if they're active
                if (activeQuestions[i] == "active") window.render(e_Questions[i]); // rendering qs
            }
            window.display();
        }
        bool endGame = false;
        for (int i = 0; i <= 30; ++i){
            if (i == 30) {
                endGame = true;
                break;
            }
            else if (activeQuestions[i] == "active") break;
        }
        if (endGame){
            int max = 0;
            std::string winningPlayer;
            std::string winningPath;
            for (int i = 0; i < game.getNop(); ++i){
                if (game.getPlayers()[i].getScore() > max){
                    std::cout << "Player " << i << " score: " << game.getPlayers()[i].getScore() << std::endl;
                    winningPlayer = game.getPlayers()[i].getName();
                    max = game.getPlayers()[i].getScore();
                    winningPath = "/graphics/" + setnum + "/Cards/Players/Player" + std::to_string(max + 1) + ".png";
                }
            }

            SDL_Texture *t_winningPlayer = window.initTexture(winningPath.c_str());
            Entity e_winningPlayer = Entity(Coords((screenWidth / 2) - (qWidth / 2), (screenHeight / 2) - (qHeight / 2)), t_winningPlayer, 1);
            window.clear();
            window.render(e_background);
            window.render(e_Headers[27]);
            window.render(e_winningPlayer);
            window.display();
        }
    }
    window.clear();
    window.destroyWindow();
    SDL_Quit;

}

/*
g++ -c -std=c++14 main.cpp RenderWindow.cpp Entity.cpp Player.cpp Game.cpp Question.cpp AllQuestions.cpp
g++ -lSDL2 -lSDL2_image main.o RenderWindow.o Entity.o Player.o Game.o Question.o AllQuestions.o -o run
./run
1
a
b
c
d
e
f
g

*/
