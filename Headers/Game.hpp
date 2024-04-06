#pragma once
#include <iostream>

class GameObject;

#include "../SDL/src/include/SDL2/SDL.h"
#include "../SDL/src/include/SDL2/SDL_image.h"
#include "../SDL/src/include/SDL2/SDL_ttf.h"
#include "Node.hpp"
#include <string>
#include "Text.hpp"



class Game{
    public :
        Game(const char *p_title, int width, int height);
        ~Game();
        void handleEvents();
        void update();
        void render();
        void clean();
        void GenerateObject();
        static SDL_Renderer *renderer;
        bool Runing() const { return isRunning; };
        void RenderNodeList(NodeList<GameObject> &list);
        void Restart();

    private:
        int cnt = 0;
        bool isRunning;
        SDL_Window *window;
        
        int width, height;
};
