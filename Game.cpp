
#include "Headers/Game.hpp"
#include "Headers/TextureManager.hpp"
#include "Headers/GameObject.hpp"
#include "Headers/Map.hpp"


using namespace std;

GameObject *player;
Text *txt;
int Score;

SDL_Renderer *Game::renderer = nullptr;



NodeList<GameObject> gametable;


std::string item[] = {"resources/cube.png", "resources/circle.png", "resources/triangle.png" , "resources/rotated_cube.png"};
Shape shapes[] = {Shape::Cube, Shape::Circle,Shape::Triangle,Shape::RotatedCube};
Colr colors[] = {Red, Green, Blue, Yellow};

Game::Game(const char *p_title, int width, int height) : width(width), height(height){
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        window = SDL_CreateWindow(p_title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_ALLOW_HIGHDPI);
        renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        isRunning = true;
        GenerateObject();
        Score = 0;
    }  else{
        isRunning = false;
    }
    if (TTF_Init() ==0){
        txt = new Text(to_string(Score),30,30,width/2-15,100);
    }
    else{
        cout << "TTF_Init wrong font" << endl;
    }
    
    
    
}

Game::~Game(){

}

void Game::Restart(){
    Score = 0;
    txt = new Text(to_string(Score),30,30,width/2-15,100);
    gametable.ClearList();
}




void Game::GenerateObject(){
    int itemindex = (rand() % 4);
    int colorindex = (rand() % 4);
    player = new GameObject(item[itemindex],width/2 - 32 , (height- 32)/2 );
    player->SetColor(colors[colorindex]);
    player->SetShape(shapes[itemindex]);
    
}

void Game::RenderNodeList(NodeList<GameObject> &list) {

if (list.getHead() == nullptr) {
        
        return; 
    }
    int spacing = 10;
    Node<GameObject>* currentNode = list.getHead();
    int totalWidth = list.getLength() * (64 + spacing);
    int startX = (width - totalWidth + spacing) / 2;
    int y = 11 * 64 - spacing;

    Node<GameObject> *tmp = nullptr;

    while(currentNode != nullptr) {
        currentNode->getObject()->setPos(startX, y);
        currentNode->getObject()->render();
        startX += 64 + spacing;
        
        
        if (list.getLength() > 3 && currentNode->getprev() != nullptr && currentNode->getnext() != nullptr){
           bool isval = currentNode->getObject()->checkColorMatch(*currentNode->getprev()->getObject(), *currentNode->getnext()->getObject());
           bool isshape = currentNode->getObject()->checkShapeMatch(*currentNode->getprev()->getObject(), *currentNode->getnext()->getObject());
           if (isval || isshape){
               tmp = currentNode;
               cout << list.getLength() << endl;
               list.deleteNode(currentNode->getprev());
                list.deleteNode(currentNode->getnext());
                  if (tmp != nullptr)
                    list.deleteNode(tmp);
                  txt->setText(to_string(++Score));
           }
           else
               continue;
        } 
            

            currentNode = currentNode->getnext();
            
            
    }
    if (list.getLength() > 14 )
            {
            list.ClearList();
            Score -= 3;
            txt->setText(to_string(--Score));
            if (Score < 0){
                txt->SetDim(width/2, 100);
                txt->SetCoor(width/2 - txt->GetWidth()/2,txt->GetHeight());
                txt->setText("U Have Already Lost my friend");
                
                
            }
            }
 



}







void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    if(Score < 0)
        return;
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
                case SDLK_LEFT:
                    gametable.AddLeft(player);
                    gametable.addusedCol(player);
                    GenerateObject();
                    break;
                case SDLK_RIGHT:
                    gametable.AddRight(player);
                    gametable.addusedCol(player);
                    GenerateObject();
                    break;
                case SDLK_UP:
                    Col_SubList<GameObject> *sub =
                        gametable.Get_Col_SubList(Red);
                        if (sub != NULL)
                            sub->Decaler();
                };
            break;
        default:
            break;
    }
}




void Game::update() {

    player->update();
}

void Game::render(){

    SDL_RenderClear(renderer);
    // map->DrawMap();
    player->render();
    RenderNodeList(gametable);
    txt->Render();
    // SDL_RenderCopy(renderer, txt,nullptr);
    SDL_RenderPresent(renderer);
    if(Score < 0){
        SDL_Delay(2000);
        Restart();
    }
}

void Game::clean(){
    delete player;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}