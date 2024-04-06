#pragma once

class Game;

#include "../SDL/src/include/SDL2/SDL.h"
#include "../SDL/src/include/SDL2/SDL_image.h"
#include "Node.hpp"
#include <iostream>
#include <string>
#include "Colr.hpp"

#include "Game.hpp"

class GameObject {
    public :
        GameObject(const std::string textureheet,int x=0 ,int y=0);
        ~GameObject(){};
        void setPos(int x = 0 , int y = 0);
        void update();
        void render();
        void SetColor(Colr);
        void SetShape(Shape);
        void SetTexture(SDL_Texture *);
        bool checkColorMatch(const GameObject &obj1,const GameObject &obj2);
        bool checkShapeMatch(const GameObject &obj1,const GameObject &obj2);
        Colr GetColor() { return Color; };
        Shape GetShape() { return shape; };
        SDL_Texture *GetTexture() { return objtexture; };
    private :
        int xpos, ypos;
        SDL_Texture *objtexture;
        SDL_Rect srcRect, destRect;
        Colr Color;
        SDL_Color texcolor;
        Shape shape;
};
