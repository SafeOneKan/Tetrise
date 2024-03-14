#include <iostream>


#include "SDL/src/include/SDL2/SDL.h"
#include "SDL/src/include/SDL2/SDL_test_images.h"

#include "Headers/GameObject.hpp"
#include "Headers/Game.hpp"
#include "Headers/Node.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    


            int width = 768,
                height = 1024;
    Game *game = new Game("game",width,height);

   
       

    const int FPS = 60;
    const int framedelay = 1000 / FPS;
    Uint64 framestart, frametime;
    while(game->Runing()){

        framestart = SDL_GetTicks64() * 0.001;
        game->handleEvents();
        game->update();
        
        game->render();

        frametime = SDL_GetTicks64() * 0.001 - framestart;
        
        if(framedelay > frametime){
            SDL_Delay(framedelay - frametime);
        }
        
    }

    game->clean();

    return 1;
}






















// SDL_Init(SDL_INIT_EVERYTHING);
//     SDL_Window *window = SDL_CreateWindow("Tetrise", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_ALLOW_HIGHDPI);

//     if (window == NULL){
//         return -1;
//     }

//     SDL_Event WindowEvent;
//     while (true){
//         if (SDL_PollEvent(&WindowEvent))
//         if (SDL_QUIT == WindowEvent.type){
//             break;

//         }
//     }
//     SDL_DestroyWindow(window);
//     SDL_Quit();
//     return EXIT_SUCCESS;