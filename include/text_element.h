#ifndef TEXT_ELEMENT_H
#define TEXT_ELEMENT_H

#include <iostream>
#include <vector>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class text_element
{
    public:
    text_element(int id, int x, int y, int w, int h, SDL_Color color, std::string s);
    text_element();
    ~text_element(){}

    int id;
    int x;
    int y;
    int w;
    int h;
    SDL_Color color;
    std::string text;

};

#endif