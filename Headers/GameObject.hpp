#pragma once

class Game;

#include "../SDL/src/include/SDL2/SDL.h"
#include "../SDL/src/include/SDL2/SDL_image.h"
#include "Node.hpp"
#include <iostream>
#include <string>



class Colr {
    public:
    Colr(int r, int g, int b) : r(r), g(g), b(b){};
    bool operator==(const Colr& other) const {
        return r == other.r && g == other.g && b == other.b;
    };
    bool operator<(const Colr& other) const {
        if (r != other.r) return r < other.r;
        if (g != other.g) return g < other.g;
        return b < other.b;
    };
    int r, g, b;
};

const Colr Red(255, 0, 0);
const Colr Green(0, 255, 0);
const Colr Blue(0, 0, 255);
const Colr Yellow(255, 255, 0);
const Colr White(255, 255, 255);
const Colr Black(0,0,0 );

class GameObject {
    public :
        GameObject(const std::string textureheet,int x=0 ,int y=0);
        ~GameObject(){};
        void setPos(int x = 0 , int y = 0);
        void update();
        void render();
        void SetColor(Colr);
       
    
    private :
        int xpos, ypos;
        SDL_Texture *objtexture;
        SDL_Rect srcRect, destRect;
        SDL_Color texcolor;
};