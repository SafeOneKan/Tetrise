
#include "Headers/GameObject.hpp"
#include "Headers/TextureManager.hpp"
#include <cstddef>


GameObject::GameObject(const std::string textureheet,int x,int y) 
{
    xpos = x ;
    ypos = y + 64;
    
    objtexture = TextureManager::LoadTexture(textureheet.c_str());
    SetColor(Black);
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = 64;
    destRect.h = 64;
}

void GameObject::SetColor(Colr color){
    texcolor.r = color.r;
    texcolor.g = color.g;
    texcolor.b = color.b;
}

void GameObject::update() {

    
}

void GameObject::setPos(int x,int y){
    xpos = destRect.x =  x;
    ypos = destRect.y = y;
}

void GameObject::render() {
    SDL_SetTextureColorMod(objtexture, texcolor.r, texcolor.g, texcolor.b);
    SDL_RenderCopy(Game::renderer,objtexture,nullptr,&destRect);
}
