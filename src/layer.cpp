#include "layer.h"

layer::layer(int id)
{
    this->id = id;
    this->font = TTF_OpenFont("./fonts/EnterCommand.ttf", 15);
}
layer::~layer()
{
}

void layer::newElement(int id, int x, int y, int w, int h, int r, int g, int b)
{
    element e(id, x, y, w, h, r, g, b);
    elements.push_back(e);
}

void layer::newTextElement(int id, int x, int y, int w, int h, SDL_Color color, std::string s)
{

    text_element e(id, x, y, w, h, color, s);
    text.push_back(e);
}

void layer::render(SDL_Renderer *render)
{
    // Renderização dos elementos
    for (long unsigned int i = 0; i < elements.size(); i++)
    {
        SDL_SetRenderDrawColor(render, elements[i].color[0], elements[i].color[1], elements[i].color[2], 255);
        SDL_RenderDrawRect(render, &elements[i].rect);
    }

    for (long unsigned int i = 0; i < text.size(); i++)
    {
        SDL_Surface *surfaceText = TTF_RenderText_Solid(font, text[i].text.c_str(), text[i].color);
        SDL_Texture *textureText = SDL_CreateTextureFromSurface(render, surfaceText);
        SDL_Rect dstrect = {text[i].x, text[i].y, text[i].w, text[i].h};
        SDL_QueryTexture(textureText, NULL, NULL, &dstrect.w, &dstrect.h);
        SDL_RenderCopy(render, textureText, NULL, &dstrect);
        SDL_FreeSurface(surfaceText);
        SDL_DestroyTexture(textureText);
    }
}
