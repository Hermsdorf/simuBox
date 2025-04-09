#include "element.h"

element::element()
{
    
}
element::element(int id, int x, int y, int w, int h, int r, int g, int b)
{
    this-> id = id;
    this->rect.x = x;
    this->rect.y = y;
    this->rect.w = w;
    this->rect.h = h;
    this->color[0] = r;
    this->color[1] = g;
    this->color[2] = b;
    this->type = RECTANGLE;
}

element::~element()
{
    // Destructor
}