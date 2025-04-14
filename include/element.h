#ifndef ELEMENT_H
#define ELEMENT_H
#define RECTANGLE_DRAW 0
#define RECTANGLE_FILL 1
#define LINE_DRAW 2

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class element
{
public:
    element();
    element(int id, int x, int y, int w, int h, SDL_Color color);
    ~element();

    int& Type() { return type; }

    int type;
    int id;
    int x;
    int y;
    int w;
    int h;
    bool isHovered;

    SDL_Color color;
    SDL_Color hoverColor;

    SDL_Rect rect;

    void setHoverColor(SDL_Color color);
    void updateHoverState(bool hover);
    SDL_Color getCurrentColor() const;

};



#endif