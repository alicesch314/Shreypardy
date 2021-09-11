// ********************
//     Preamble
// ********************

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime> 
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.h"
#include "RenderWindow.h"

// ********************
// Getters and Setters
// ********************

Coords Entity::getPos(){
    return Pos;
}
float Entity::getScale(){
    return Scale;
}
SDL_Texture *Entity::getTexture(){
    return Texture;
}
SDL_Rect Entity::getCurrFrame(){
    return currFrame;
}

float Coords::getX(){
    return X;
}
float Coords::getY(){
    return Y;
}

// ********************
//       Functs
// ********************

// Returns point size of texture
SDL_Point getSize(SDL_Texture *texture) {
    SDL_Point size;
    SDL_QueryTexture(texture, NULL, NULL, &size.x, &size.y);
    return size;
}

// ********************
//    Constructors
// ********************

Entity::Entity(Coords pos, SDL_Texture *texture, float scale) 
: Pos(pos), Scale(scale), Texture(texture){
    currFrame.x = 0;
    currFrame.y = 0;
    currFrame.w = getSize(texture).x * scale;
    currFrame.h = getSize(texture).y * scale;
}

Coords::Coords(float x, float y) : X(x), Y(y) {}