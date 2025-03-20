#ifndef _WINDOW_H
#define _WINDOW_H
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

#define DEFAULT_SCREEN_WIDTH 640
#define DEFAULT_SCREEN_HEIGHT 480
#define DEFAULT_R 0
#define DEFAULT_G 0
#define DEFAULT_B 0
#define DEFAULT_NAME "window"

class window
{
    public:
    window();
    window(std::string win_name);
    window(std::string win_name, int r, int g, int b, int height, int width);
    ~window();

    void show();

    SDL_Window* Window = NULL;
    SDL_Renderer* render = NULL;

    private:

    int r, g, b;
    int height, width;
    std::string win_name;

};

#endif