#include "text_element.h"

text_element::text_element(int id, int x, int y, int w, int h, SDL_Color color, std::string s)
{
    this->id = id;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->color = color;
    this->text = s;

}