#ifndef LAYER_H
#define LAYER_H


#include "element.h"




class layer 
{
public:
    layer(int id);
    ~layer();

    void setId(int id) { this->id = id; }
    int getId() { return id; }
    void newElement(int id, int x, int y, int w, int h, int r, int g, int b);

    std::vector<element> elements;

    //SDL_Rect rect;

    int id;

private:
};

#endif