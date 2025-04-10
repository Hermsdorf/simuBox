#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

#include "./include/window.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef unsigned char uint8;

int main()
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "simuBox initialized successfully!" << std::endl;
    }

    if (TTF_Init() == -1)
    {
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
    }
    else
    {
        std::cout << "SDL_ttf initialized successfully!" << std::endl;
    }

    
    window win("simuBox", 3, 6, 100, SCREEN_HEIGHT, SCREEN_WIDTH);

    
    win.add_element_to_workbench(0, 10, 10, 32, 32, {255, 255, 255});

    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            switch (e.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    quit = true;
                    break;
                }
                break;
            case SDL_MOUSEMOTION:
                int x = e.motion.x;
                int y = e.motion.y;
                if (x < SCREEN_WIDTH && y < SCREEN_HEIGHT && x > win.layers[0].elements[0].rect.w && y > win.layers[0].elements[0].rect.h)
                {
                    win.layers[0].elements[0].rect.x = x - win.layers[0].elements[0].rect.w;
                    win.layers[0].elements[0].rect.y = y - win.layers[0].elements[0].rect.h;
                }
                break;
            }
        }

        win.show();
    }


    SDL_Quit();
}

// setBackColor(3, 6, 100);
// setColor(255, 255, 255);

// std::cout << "X: " << win.layers[0].elements[0].rect.x<<std::endl;
// win.layers[0].newElement(0, 10, 10, 32, 32, 255, 255, 255);

// SDL_Rect rect = win.layers[0].rect;
//  rect.x = win.layers[0].elements[0].x;
//  rect.y = win.layers[0].elements[0].y;
//  rect.w = win.layers[0].elements[0].w;
//  rect.h = win.layers[0].elements[0].h;

// SDL_RenderDrawRect(win.render, &win.layers[0].elements[0].rect); // desenha o retangulo pertencente a tela(também será substituído pelo metodo renderElements)

// setBackColor(3, 6, 100);
// setColor(255, 255, 255);
// SDL_SetRenderDrawColor(win.render, 3, 6, 100, 255); // seta a cor da tela desenha fundo da tela
// SDL_RenderClear(win.render); // desenha o fundo da tela

// SDL_DestroyTexture(text);
// SDL_DestroyRenderer(atributos);
// SDL_DestroyWindow(window);

// SDL_RenderCopy(atributos, text, NULL, &rect2);
// SDL_RenderDrawRect(win.render, &rect);

// SDL_SetRenderDrawColor(win.render, 255, 255, 255, 255); // seta a cor do retangulo presente na tela(será substituído pelo metodo renderElements)
// SDL_RenderDrawRect(win.render, &win.layers[0].elements[0].rect); // desenha o retangulo pertencente a tela(também será substituído pelo metodo renderElements)

// SDL_RenderPresent(win.render); // quando a renderização das layers e seus elementos estiverem prontas,  talvez
//  dê para adicionar este comando no final do método show logo após a renderização das layers.

// TTF_CloseFont(font);