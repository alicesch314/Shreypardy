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

#include "RenderWindow.h"
#include "Entity.h"

// ********************
//       Functs
// ********************

void RenderWindow::initWindow(const char *title, int width, int height){
    Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
        width, height, SDL_WINDOW_SHOWN);
    if (Window == NULL){
        std::cout << "Window faield to init. Error: " << SDL_GetError() << std::endl;
    }
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    //SDL_SetRenderDrawColor(Renderer, 170, 198, 255, 255);

}
/*
void RenderWindow::initSurface(const char *path){
    SDL_Surface *surfaceScreen = NULL;
    SDL_Surface *surfaceImage = NULL;
    surfaceScreen = SDL_GetWindowSurface(Window);
    if (surfaceScreen == NULL){
        std::cout << "Unable to init surface screen. Error: " << SDL_GetError() << std::endl;
    }
    surfaceImage = SDL_LoadBMP(path);
    if (surfaceImage == NULL){
        std::cout << "Unable to init surface image. Error: " << SDL_GetError() << std::endl;
    }
    SDL_BlitSurface(surfaceImage,NULL, surfaceScreen, NULL);
    SDL_FreeSurface(surfaceScreen);
    SDL_UpdateWindowSurface(Window);

}
*/

SDL_Texture *RenderWindow::initTexture(const char * filePath){
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(Renderer, filePath);

    if (texture == NULL){
        std::cout << "Texture failed to init. Error: " << SDL_GetError() << std::endl;
    }
    return texture;
}

void RenderWindow::destroyWindow(){
    SDL_DestroyWindow(Window);
}

void RenderWindow::clear(){
    SDL_RenderClear(Renderer);
}

void RenderWindow::render(Entity &entity){
    // Source
    SDL_Rect source;
    source.x = entity.getCurrFrame().x;
    source.y = entity.getCurrFrame().y;
    source.w = entity.getCurrFrame().w;
    source.h = entity.getCurrFrame().h;

    // Destination
    SDL_Rect dest;
    float scale = entity.getScale();
    dest.x = entity.getPos().getX(); // x location
    dest.y = entity.getPos().getY(); // y location 
    dest.w = entity.getCurrFrame().w * scale;
    dest.h = entity.getCurrFrame().h * scale;

    SDL_RenderCopy(Renderer, entity.getTexture(), &source, &dest);
}

void RenderWindow::display(){
        SDL_RenderPresent(Renderer);
}

// ********************
//     Constructor
// ********************

RenderWindow::RenderWindow() {}