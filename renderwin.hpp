// #pragma once
#include "SDL/src/include/SDL2/SDL.h"
#include "Entity.hpp"



class RenderWindow {
public:
  RenderWindow(const char *p_title, int width, int height);
  SDL_Texture *LoadTexture(const char *p_FilePath);
  void Clear();
  void Render(Entity &ent);
  void Display();

  void CleanUp();
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  
};