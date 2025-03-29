#include "layer.h"

layer::layer(int id)
{
    this->id = id;
    
}
layer::~layer()
{
  
}

void layer::newElement(int id, int x, int y, int w, int h, int r, int g, int b)
{
    element e(id, x, y, w, h, r, g, b);
    elements.push_back(e);
}

void layer::render(SDL_Renderer* render)
    {
        for(long unsigned int i = 0; i < elements.size(); i++)
        {
            SDL_SetRenderDrawColor(render, elements[i].color[0], elements[i].color[1], elements[i].color[2], 255);
            SDL_RenderDrawRect(render, &elements[i].rect);
        }
    }