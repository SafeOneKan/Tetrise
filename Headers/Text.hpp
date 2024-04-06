#pragma once

class Game;
#include <iostream>
#include "../SDL/src/include/SDL2/SDL.h"
#include "../SDL/src/include/SDL2/SDL_image.h"
#include "../SDL/src/include/SDL2/SDL_ttf.h"
#include "Colr.hpp"
#include "TextureManager.hpp"


class Text {

    private:
        std::string sentence;
        int FontSize = 30;
        TTF_Font *font = TTF_OpenFont("ressources/ka1.ttf", FontSize);
        SDL_Color Color ;
        SDL_Texture *TheText;
        SDL_Rect dest;
        
    public:
        
        SDL_Color SetColor(Colr clr){
            Color.r = clr.r;
            Color.g = clr.g;
            Color.b = clr.b;
            Color.a = 255;
            return Color;
        }



        Text(std::string text ,int w = 40,int h = 40, int x = 0 , int y = 0) : sentence(text) , Color(SetColor(White)) {
            TheText = TextureManager::LoadTextureFromText(sentence.c_str(),Color);
            dest.w =  w;
            dest.h = h;
            dest.x = x;
            dest.y = y;
        }
        void SetCoor(int x,int y){
            dest.x = x;
            dest.y = y;
        }
        int GetWidth(){
            return dest.w;
        }
        int GetHeight(){
            return dest.h;
        }

        void SetDim(int w,int h){
            dest.w = w;
            dest.h = h;
        }

        void setText(std::string x){
            sentence = x;
            TheText = TextureManager::LoadTextureFromText(sentence.c_str(),Color);
        };

        std::string GetSentence() { return sentence; };
        void Render(){
            TextureManager::Draw(TheText,dest);
        }
};