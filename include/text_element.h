#ifndef TEXT_ELEMENT_H
#define TEXT_ELEMENT_H

#include <iostream>
#include <vector>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define SMALL_FONT 0
#define MEDIUM_FONT 1
#define LARGE_FONT 2

class text_element
{
    public:
    text_element(int id, int x, int y, int w, int h, SDL_Color color, std::string text, int size);
    text_element();
    ~text_element(){}

    int id;
    int x;
    int y;
    int w;
    int h;
    int size;
    SDL_Color color;
    std::string text;

};

#endif