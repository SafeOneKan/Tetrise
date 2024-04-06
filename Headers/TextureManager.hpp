#pragma once

#include "../SDL/src/include/SDL2/SDL.h"
#include "../SDL/src/include/SDL2/SDL_image.h"
#include "../SDL/src/include/SDL2/SDL_ttf.h"


class TextureManager {
    public:
    static SDL_Texture *LoadTexture(const char *filename);
    static SDL_Texture *LoadTextureFromText(const char *txt,SDL_Color color);
    static void Draw(SDL_Texture *texture, SDL_Rect dst);

};
