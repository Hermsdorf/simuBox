#include "element.h"

element::element()
{
    
}
element::element(int id, int x, int y, int w, int h, SDL_Color color)
{
    this-> id = id;
    this->rect.x = x;
    this->rect.y = y;
    this->rect.w = w;
    this->rect.h = h;
    this->color = color;
    this->type = RECTANGLE_DRAW;
}

element::~element()
{
    // Destructor
}