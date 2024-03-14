#pragma once
#include "Game.hpp"


class Map{
    public:
        Map();
        ~Map();
        void LoadMap();
        void DrawMap();

    private:
        SDL_Rect src, dst;
        SDL_Texture *metal, *grass, *water;
        int tilemap[20][25];
};