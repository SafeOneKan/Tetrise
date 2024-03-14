#pragma once
#include "SDL/src/include/SDL2/SDL.h"
class Entity {
    private:
        double x, y;
        

        SDL_Rect CurrentFrame;
        SDL_Texture *tex;
    public:
        Entity(double x, double y, SDL_Texture *tex,int w,int h);
        double GetX() const { return x; };
        double GetY() const { return y; };
        SDL_Texture *GetTexture() const { return tex; };
        SDL_Rect GetCurrentFrame() const { return CurrentFrame; };
};