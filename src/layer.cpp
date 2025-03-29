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