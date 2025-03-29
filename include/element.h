#ifndef ELEMENT_H
#define ELEMENT_H
#define RECTANGLE 0


#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class element
{
public:
    element();
    element(int id, int x, int y, int w, int h, int r, int g, int b);
    ~element();

    int type;
    int id;
    int x;
    int y;
    int w;
    int h;
    int color[3];

    SDL_Rect rect;

};



#endif