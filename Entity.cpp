
#include "Entity.hpp"


Entity::Entity(double px, double py,SDL_Texture *ptex,int pw =1406, int ph = 355) : x(px), y(py), tex(ptex)
{
    CurrentFrame.x = 0;
    CurrentFrame.y = 0;
    CurrentFrame.w = pw;
    CurrentFrame.h = ph;
}