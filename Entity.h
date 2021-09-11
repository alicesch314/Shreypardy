// ********************
//     Preamble
// ********************

#ifndef ENTITY_H
#define ENTITY_H

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
//       Class
// ********************

class Coords{
private:
    float X;
    float Y;
public:
    Coords(float x, float y);
    float getX();
    float getY();
};

class Entity{
private:
    Coords Pos;
    float Scale;
    SDL_Rect currFrame;
    SDL_Texture * Texture;

public:
    Entity(Coords pos, SDL_Texture *texture, float scale);
    // 
    void init();
    Coords getPos();
    float getScale();
    SDL_Texture* getTexture();
    SDL_Rect getCurrFrame();
};

#endif // ENTITY_H