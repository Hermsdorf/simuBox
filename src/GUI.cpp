#include "window.h"

void window::make_workbench_layer()
{
    layer l(0);
    layers.push_back(l);
}

void window::make_GUI_layer()
{
    layer l(1);
    l.newElement(0, 1, (SCREEN_HEIGHT - (SCREEN_HEIGHT / 5)), SCREEN_WIDTH - 1, SCREEN_HEIGHT / 5, 255, 255, 255);
    l.newElement(1, 4, (SCREEN_HEIGHT - (SCREEN_HEIGHT / 5)) + 3, SCREEN_WIDTH - 7, SCREEN_HEIGHT / 5 - 6, 255, 255, 255);
    l.newTextElement(0, 10, 10, 32, 32, {255, 255, 255}, "simuBox");
    layers.push_back(l);
}

layer &window::workbench()
{
    return layers[0];
}

void window::add_element_to_workbench(int id, int x, int y, int w, int h, int r, int g, int b)
{
    workbench().newElement(id, x, y, w, h, r, g, b);
}

