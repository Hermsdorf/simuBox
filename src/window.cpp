#include "window.h"

window::window()
{
    this->r = DEFAULT_R;
    this->g = DEFAULT_G;
    this->b = DEFAULT_B;
    this->height = DEFAULT_SCREEN_HEIGHT;
    this->width = DEFAULT_SCREEN_WIDTH;
    this->win_name = DEFAULT_NAME;
    this->Window = SDL_CreateWindow(DEFAULT_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    this->render = SDL_CreateRenderer(this->Window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(this->render, DEFAULT_R, DEFAULT_G, DEFAULT_B, 255);
    SDL_RenderClear(this->render);
}

window::window(std::string win_name)
{
    this->r = DEFAULT_R;
    this->g = DEFAULT_G;
    this->b = DEFAULT_B;
    this->height = DEFAULT_SCREEN_HEIGHT;
    this->width = DEFAULT_SCREEN_WIDTH;
    this->win_name = win_name;
    this->Window = SDL_CreateWindow(win_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    this->render = SDL_CreateRenderer(this->Window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(this->render, DEFAULT_R, DEFAULT_G, DEFAULT_B, 255);
    SDL_RenderClear(this->render);
}

window::window(std::string win_name, int r, int g, int b, int height, int width)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->height = height;
    this->width = width;
    this->win_name = win_name;

    this->Window = SDL_CreateWindow(win_name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    this->render = SDL_CreateRenderer(this->Window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(this->render, r, g, b, 255);
    SDL_RenderClear(this->render);
    SDL_RenderPresent(this->render);
    make_workbench_layer();
}

window::~window()
{
    SDL_DestroyRenderer(this->render);
    SDL_DestroyWindow(this->Window);
}

void window::show()
{
    SDL_SetRenderDrawColor(this->render, this->r, this->g, this->b, 255);
    SDL_RenderClear(this->render);
    this->renderLayers();
    SDL_RenderPresent(this->render);
}

void window::renderLayers()
{
    for(long unsigned int i = 0; i < layers.size(); i++)
    {
        layers[i].render(this->render);
    }
}