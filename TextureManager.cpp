#include "Headers/TextureManager.hpp"
#include "Headers/Game.hpp"


SDL_Texture* TextureManager::LoadTexture (const char * filename){
    SDL_Surface *surface = IMG_Load(filename);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(Game::renderer,surface);
    SDL_FreeSurface(surface);
    return texture;
}
void TextureManager::Draw(SDL_Texture *texture, SDL_Rect dst)
{
    SDL_RenderCopy(Game::renderer,texture,nullptr,&dst);
}