#ifndef LAYER_H
#define LAYER_H

#include <functional>
#include "element.h"
#include "physical_element.h"
#include "text_element.h"
#include "timer.h"

class layer
{
    public:
    layer(int id);
    ~layer();

    void setId(int id) { this->id = id; }
    int getId() { return id; }
    void render(SDL_Renderer *render);

    void newElement(int type, int x, int y, int w, int h, SDL_Color color);
    void newTextElement(int x, int y, int w, int h, SDL_Color color, std::string s, int size);
    
    void setElementType(int id, int type) { elements[id].Type() = type; }
    void setTextElementString(int id, std::string s) { text[id].text = s; }
    element& getElement(int id) { return elements[id]; }
    text_element& getTextElement(int id) { return text[id]; }

    // Métodos para gerenciamento de eventos
    TTF_Font *font;

    std::vector<element> elements;
    std::vector<physical_element> physical_elements;
    std::vector<text_element> text;


    int id;

    private:
};

#endif