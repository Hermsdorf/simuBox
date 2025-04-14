#include "window.h"

void window::make_default_layer()
{
    layer workbench(0);
    layer GUI(1);
    layers.push_back(workbench);
    layers.push_back(GUI);
}

void window::make_GUI_layer()
{
    int x0 = 0;
    int y0 = SCREEN_HEIGHT - (SCREEN_HEIGHT / 5);
    int x0_in = 4;
    int y0_in = SCREEN_HEIGHT - (SCREEN_HEIGHT / 5) + 3;
    
    SDL_Color font_color = {3, 6, 100};
    GUI().newElement(RECTANGLE_FILL,1, (SCREEN_HEIGHT - (SCREEN_HEIGHT / 5)), SCREEN_WIDTH - 1, SCREEN_HEIGHT / 5, {168,168,168});
    GUI().newElement(RECTANGLE_DRAW,4, (SCREEN_HEIGHT - (SCREEN_HEIGHT / 5)) + 3, SCREEN_WIDTH - 7, SCREEN_HEIGHT / 5 - 6, {3, 6, 100});
    GUI().newElement(RECTANGLE_DRAW,6, (SCREEN_HEIGHT - (SCREEN_HEIGHT / 5)) + 5, SCREEN_WIDTH - 11, SCREEN_HEIGHT / 5 - 10, {3, 6, 100});

    GUI().newElement(RECTANGLE_FILL,20, y0, 55, 21, {3, 6, 100});
    GUI().newTextElement(25 , y0, 32, 15, {168,168,168} , "INFOS",1);
    
    
    GUI().newTextElement(25 , y0+30, 32, 15, {3, 6, 100} , "m  = 10kg",0);
    GUI().newTextElement(25 , y0+45, 32, 15, {3, 6, 100} , "v0 = 10m/s",0);
    GUI().newTextElement(25 , y0+60, 32, 15, {3, 6, 100} , "a  = 10m/s",0);
    
    GUI().newTextElement(125 , y0+30, 32, 15, {3, 6, 100} , "G = 10m/s",0);
    GUI().newTextElement(125 , y0+45, 32, 15, {3, 6, 100} , "u = 0.015",0);
    GUI().newTextElement(125 , y0+60, 32, 15, {3, 6, 100} , "Time: 00:00:00",0);
   
    


    //layers.push_back(l);
}

layer &window::workbench()
{
    return layers[0];
}

void window::add_element_to_workbench(int type, int id, int x, int y, int w, int h, SDL_Color c)
{
    workbench().newElement(type,x, y, w, h, c);
}

