
#include "Headers/GameObject.hpp"
#include "Headers/TextureManager.hpp"
#include <cstddef>



GameObject::GameObject(const std::string textureheet,int x,int y)  : Color(Black)
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
    this->Color = color;
}

void GameObject::SetShape(Shape pshape) {
    shape = pshape;
}

bool GameObject::checkColorMatch(const GameObject &obj1,const GameObject &obj2)
{
    if (this->Color == obj1.Color && this->Color == obj2.Color){
        
        return true;
    }
    return false;
}

bool GameObject::checkShapeMatch(const GameObject &obj1,const GameObject &obj2){
    if (this->shape == obj1.shape && this->shape == obj2.shape){
        return true;
    }
    return false;
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



void GameObject::SetTexture(SDL_Texture* tex){
    this->objtexture = tex;
}