
#include "Headers/Game.hpp"
#include "Headers/TextureManager.hpp"
#include "Headers/GameObject.hpp"
#include "Headers/Map.hpp"

using namespace std;

GameObject *player;
Map *map;
SDL_Renderer *Game::renderer = nullptr;
NodeList<GameObject> gametable;
std::string item[] = {"resources/cube.png", "resources/circle.png", "resources/triangle.png" , "resources/rotated_cube.png"};
Colr colors[] = {Red, Green, Blue, Yellow};
 
void Game::GenerateObject(){
    int itemindex = (rand() % 4);
    int colorindex = (rand() % 4);
    player = new GameObject(item[itemindex],width/2 - 32 , height/2 - 32);
    player->SetColor(colors[colorindex]);
    
}

Game::Game(const char *p_title, int width, int height) : width(width), height(height){
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        window = SDL_CreateWindow(p_title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_ALLOW_HIGHDPI);
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        isRunning = true;
        map = new Map();
        GenerateObject();

    }  else{
        isRunning = false;
    }
    
    
}


void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_LEFT:
                    gametable.AddLeft(player);
                    GenerateObject();
                    break;
                case SDLK_RIGHT:
                    gametable.AddRight(player);
                    GenerateObject();
                    break;
                };
            break;
        default:
            break;
    }
}


void Game::RenderNodeList(NodeList<GameObject> list){

    Node<GameObject> *currentNode = list.getHead();
    int x = 64; 
    int y = 14 * 64; 
    int spacing = 10; 
    while(currentNode != nullptr){
        currentNode->getObject()->setPos(x, y);
        currentNode->getObject()->render();
        
        x += 64 + spacing;
        currentNode = currentNode->getnext();
    }
}

void Game::update() {

    player->update();
}

void Game::render(){

    SDL_RenderClear(renderer);
    map->DrawMap();
    player->render();
    RenderNodeList(gametable);
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    delete player;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}