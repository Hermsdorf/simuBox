#ifndef _WINDOW_H
#define _WINDOW_H
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include "layer.h"

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

    static const int SCREEN_WIDTH = 640;
    static const int SCREEN_HEIGHT = 480;

    
    SDL_Window* Window = NULL;
    SDL_Renderer* render = NULL;
    SDL_TimerID timer;

    std::vector<layer> layers;

    unsigned int t_ms = 0; 
    
    void show();
    void make_default_layer();
    void make_GUI_layer();
    void add_element_to_workbench(int type, int id, int x, int y, int w, int h, SDL_Color c);
    layer &workbench();
    layer &GUI(){return layers[1];}

    
    void refresh_workbench_elements();
    void addLayer(layer l);
    

    void renderLayers();

 
    
    private:

    int r, g, b;
    int height, width;
    std::string win_name;

};

#endif