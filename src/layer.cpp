#include "layer.h"

#ifdef DEBUG
int debugLevel = 1; // 0 = desligado, 1 = básico, 2 = detalhado
#define DEBUG_LOG(x, level)                        \
    if (debugLevel >= level)                       \
    {                                              \
        std::cout << "[DEBUG] " << x << std::endl; \
    }
#else
#define DEBUG_LOG(x, level) // Não faz nada em release
#endif

layer::layer(int id)
{
    this->id = id;
    this->font = TTF_OpenFont("./fonts/EnterCommand.ttf", 16);
}
layer::~layer()
{
}

void layer::newElement(int type, int x, int y, int w, int h, SDL_Color color)
{
    element e(elements.size(), x, y, w, h, color);
    e.setHoverColor(e.color);
    e.type = type;
    elements.push_back(e);
}

void layer::newTextElement(int x, int y, int w, int h, SDL_Color color, std::string s, int size)
{

    text_element e(text.size(), x, y, w, h, color, s, size);
    text.push_back(e);
}

void layer::render(SDL_Renderer *render)
{
    // Renderização dos elementos
    for (long unsigned int i = 0; i < elements.size(); i++)
    {
        SDL_SetRenderDrawColor(render, elements[i].getCurrentColor().r, elements[i].getCurrentColor().g, elements[i].getCurrentColor().b, 255);
        if (elements[i].type == RECTANGLE_FILL)
        {
            SDL_RenderFillRect(render, &elements[i].rect);
        }
        else if (elements[i].type == RECTANGLE_DRAW)
        {
            SDL_RenderDrawRect(render, &elements[i].rect);
        }
        else if (elements[i].type == LINE_DRAW)
        {
            SDL_RenderDrawLine(render, elements[i].x, elements[i].y, elements[i].w, elements[i].h); //x = x1, y= y1, w = x2, h = y2
        }
    }

    // Renderização dos elementos físicos
    for(long unsigned int i = 0; i < physical_elements.size(); i++)
    {
        
    }

    for (long unsigned int i = 0; i < text.size(); i++)
    {
        if (text[i].size == SMALL_FONT)
        {
            TTF_SetFontSize(font, 16);
        }
        else if (text[i].size == MEDIUM_FONT)
        {
            TTF_SetFontSize(font, 24);
        }
        else if (text[i].size == LARGE_FONT)
        {
            TTF_SetFontSize(font, 32);
        }
        SDL_Surface *surfaceText = TTF_RenderText_Solid(font, text[i].text.c_str(), text[i].color);
        SDL_Texture *textureText = SDL_CreateTextureFromSurface(render, surfaceText);
        SDL_Rect dstrect = {text[i].x, text[i].y, text[i].w, text[i].h};
        SDL_QueryTexture(textureText, NULL, NULL, &dstrect.w, &dstrect.h);

#ifdef DEBUG
        static bool alreadyPrinted = false;
        if (!alreadyPrinted)
        {
            std::cout << std::endl
                      << "DEBUG" << std::endl;

            std::cout << "Text: " << text[i].text << std::endl
                      << "Size: " << text[i].size << std::endl
                      << "X: " << text[i].x << std::endl
                      << "Y: " << text[i].y << std::endl
                      << "W: " << dstrect.w << std::endl
                      << "H: " << dstrect.h << std::endl
                      << "Color: " << (int)text[i].color.r << " " << (int)text[i].color.g << " " << (int)text[i].color.b << std::endl;
            alreadyPrinted = true;
        }
#endif

        SDL_RenderCopy(render, textureText, NULL, &dstrect);
        SDL_FreeSurface(surfaceText);
        SDL_DestroyTexture(textureText);
    }
}

