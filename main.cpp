#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

#include "./include/window.h"


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef unsigned char uint8;

SDL_Renderer* atributos = NULL;

void setColor(uint8 r, uint8 g, uint8 b)
{
    SDL_SetRenderDrawColor(atributos, r, g, b,255);
}

void setBackColor(uint8 r, uint8 g, uint8 b)
{
    setColor(r, g, b);
    SDL_RenderClear(atributos);
}

int main()
{
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        std::cout << "SDL initialized successfully!" << std::endl;
    }
    
    
    if(TTF_Init() == -1)
    {
        std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
    }
    else
    {
        std::cout << "SDL_ttf initialized successfully!" << std::endl;
    }
    
    TTF_Font* font = TTF_OpenFont("./fonts/EnterCommand.ttf", 15);
    if(font == NULL)
    {
        std::cout << "Failed to load lazy font! SDL_ttf Error: " << TTF_GetError() << std::endl;
    }
    
    window win("simuBox", 3, 6, 100, SCREEN_HEIGHT, SCREEN_WIDTH);

    //SDL_Surface* surfaceText = TTF_RenderText_Solid(font, "Time: ", {255, 255, 255});
    //SDL_Texture* text = SDL_CreateTextureFromSurface(win.render, surfaceText);

    //SDL_FreeSurface(surfaceText);

    //setBackColor(3, 6, 100);
    //setColor(255, 255, 255);

    std::vector<SDL_Rect*> rects;

    SDL_Rect rect;
    rect.x = SCREEN_HEIGHT/2;
    rect.y = SCREEN_WIDTH/2;
    rect.w = 32;
    rect.h = 32;

    SDL_Rect rect2;
    rect2.x = 10;
    rect2.y = 10;
    rect2.w = 50;
    rect2.h = 25;

    SDL_RenderDrawRect(win.render, &rect);

    bool quit = false;
    SDL_Event e;

    while(!quit)
    {
        while(SDL_PollEvent(&e) != 0)
        {
            switch(e.type)
            {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch(e.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            quit = true;
                            break;
                    }
                    break;
                case SDL_MOUSEMOTION:
                    int x = e.motion.x;
                    int y = e.motion.y;
                    if(x < SCREEN_WIDTH && y < SCREEN_HEIGHT && x > rect.w && y > rect.h)
                    {
                        rect.x = x - 32;
                        rect.y = y - 32;
                    }
                    break;
            }
        }

        //setBackColor(3, 6, 100);
        //setColor(255, 255, 255);
        //SDL_SetRenderDrawColor(win.render, 3, 6, 100, 255); // seta a cor da tela desenha fundo da tela
        //SDL_RenderClear(win.render); // desenha o fundo da tela
        win.show();
        SDL_SetRenderDrawColor(win.render, 255, 255, 255, 255); // seta a cor do retangulo presente na tela
        SDL_RenderDrawRect(win.render, &rect); // desenha o retangulo pertencente a tela
        //SDL_RenderCopy(atributos, text, NULL, &rect2);
        SDL_RenderDrawRect(win.render, &rect);
        SDL_RenderPresent(win.render);
    }

    //SDL_DestroyTexture(text);
    //SDL_DestroyRenderer(atributos);
    //SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    SDL_Quit();

}