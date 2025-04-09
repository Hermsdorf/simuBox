#ifndef LAYER_H
#define LAYER_H

#include "element.h"
#include "text_element.h"




class layer 
{
public:
    layer(int id);
    ~layer();

    void setId(int id) { this->id = id; }
    int getId() { return id; }
    void newElement(int id, int x, int y, int w, int h, int r, int g, int b);
    void newTextElement(int id, int x, int y, int w, int h, SDL_Color color, std::string s);
    void render(SDL_Renderer* render);
    void render_text_elements(SDL_Renderer* render);

    TTF_Font *font ;

    std::vector<element> elements;
    std::vector<text_element> text;


    int id;

private:
};

#endif