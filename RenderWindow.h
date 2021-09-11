// ********************
//     Preamble
// ********************

#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

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

// ********************
//     Constants
// ********************

// Screen size and question sizes
const float screenWidth = 1400;
const float screenHeight = 800;
const float qWidth = 180;
const float qHeight = 117;
const float headerWidth = 500;
const float headerHeight = 75;
const float spaceX = (screenWidth - qWidth * 6) / 7; // 45.71
const float spaceY = (screenHeight - headerHeight - qHeight * 5) / 6; // 23.33

// ********************
//       Class
// ********************

class RenderWindow{
private:
    SDL_Window *Window;
    SDL_Renderer *Renderer;

public:
    RenderWindow();
    //
    void initWindow(const char *title, int width, int height); 
    void initSurface(const char *path);
    SDL_Texture *initTexture(const char * filePath);
    void destroyWindow();
    
    void clear();
    void render(Entity &entity);
    void display(); // displays screen
};

#endif // RENDERWINDOW_H