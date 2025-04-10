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
    int x0_in = 4;
    int y0_in = SCREEN_HEIGHT - (SCREEN_HEIGHT / 5) + 3;
    
    SDL_Color font_color = {3, 6, 100};
    GUI().newElement(0, 1, (SCREEN_HEIGHT - (SCREEN_HEIGHT / 5)), SCREEN_WIDTH - 1, SCREEN_HEIGHT / 5, {168,168,168});
    GUI().newElement(1, 4, (SCREEN_HEIGHT - (SCREEN_HEIGHT / 5)) + 3, SCREEN_WIDTH - 7, SCREEN_HEIGHT / 5 - 6, {168,168,168});
    GUI().setElementType(1, RECTANGLE_FILL);
    GUI().newElement(2,10, y0_in - 15, 55, 21, {3, 6, 100});
    GUI().setElementType(2, RECTANGLE_FILL);
    GUI().newTextElement(1, x0_in +10 , y0_in + 7.5+20, 32, 15, font_color , "Text1",1);
    GUI().newTextElement(2, x0_in +10 , y0_in + 7.5+40, 32, 15, font_color , "Text3",1);
    GUI().newTextElement(3, x0_in +10 , y0_in + 7.5+60, 32, 15, font_color , "Text4",1);
    GUI().newTextElement(4, 17 , y0_in -15, 32, 15, {168,168,168} , "infos",1);



    //layers.push_back(l);
}

layer &window::workbench()
{
    return layers[0];
}

void window::add_element_to_workbench(int id, int x, int y, int w, int h, SDL_Color c)
{
    
    workbench().newElement(id, x, y, w, h, c);
}

