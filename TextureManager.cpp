#include "Headers/TextureManager.hpp"

#include "Headers/Game.hpp"

SDL_Texture* TextureManager::LoadTexture (const char * filename){
    SDL_Surface *surface = IMG_Load(filename);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(Game::renderer,surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* TextureManager::LoadTextureFromText (const char *txt,SDL_Color color){
    TTF_Font *font = TTF_OpenFont("resources/ka1.ttf", 28);
    SDL_Surface *surface = TTF_RenderText_Solid(font, txt, color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(Game::renderer,surface);
    SDL_FreeSurface(surface);
    return texture;
}

void TextureManager::Draw(SDL_Texture *texture, SDL_Rect dst)
{
    
    SDL_RenderCopy(Game::renderer,texture,nullptr,&dst);
}