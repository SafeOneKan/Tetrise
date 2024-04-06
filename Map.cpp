#include "Headers/Map.hpp"
#include "Headers/TextureManager.hpp"


Map::Map()
{
    metal = TextureManager::LoadTexture("resources/cube.png");
    grass = TextureManager::LoadTexture("resources/grass.png");
    water = TextureManager::LoadTexture("resources/water.png");

    LoadMap();

    dst.x = dst.y = 0;
    dst.w = dst.h = 64;
}


void Map::LoadMap(){
    for (int row = 0; row < 16;row++){
        for (int col = 0; col < 12; col++){
            if (row == 15 || col == 0 || col == 11){
                if (row == 15 || col == 0 || col == 11)
                this->tilemap[row][col] = 1;
            }
            else{
                
                    this->tilemap[row][col] = 0;
                
            }
        }
    }
};

void Map::DrawMap(){
    int type = 0;
    for (int row = 0; row < 16;row++){
        for (int col = 0; col < 12; col++){
            dst.x = col * 64;
            dst.y = row * 64;
            type = tilemap[row][col];
            switch(type){
                
                case 1:
                    TextureManager::Draw(metal, dst);
                    break;
                // case 0:
                //     TextureManager::Draw(water, dst);
                //     break;
                default:
                    break;
            }
        }
    }
}