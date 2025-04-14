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
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->color = color;
    this->type = RECTANGLE_DRAW;
    this->isHovered = false;
}

element::~element()
{
    // Destructor
}

void element::setHoverColor(SDL_Color color) {
    hoverColor = color;
}

void element::updateHoverState(bool hover) {
    isHovered = hover;
}

SDL_Color element::getCurrentColor() const {
    return isHovered ? hoverColor : color;
}