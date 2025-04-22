#ifndef PHYSICAL_ELEMENT_H
#define PHYSICAL_ELEMENT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define EDGE 1
#define QUAD 2
#define TRIANGLE 3

class physical_element
{
    public:
    //physical_element(int id, int type, int x, int y, int w, int h, SDL_Color color);
    physical_element(int id, int type, SDL_Point p0,SDL_Point p1 , SDL_Color color);
    physical_element(int id, int type, SDL_Point p0,SDL_Point p1 ,SDL_Point p2,  SDL_Color color);
    physical_element(int id, int type, SDL_Point p0,SDL_Point p1 ,SDL_Point p2, SDL_Point p3, SDL_Color color);
    physical_element();
    ~physical_element(){}

    unsigned int id;
    unsigned int x;
    unsigned int y;
    unsigned int w;
    unsigned int h;
    unsigned int type;

    SDL_Point p0;
    SDL_Point p1;
    SDL_Point p2;
    SDL_Point p3;
    SDL_Point center;
    float angle;
    SDL_Color color;

};


#endif