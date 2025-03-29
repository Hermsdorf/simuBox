#include "window.h"

void window::make_workbench_layer()
{
    layer l(0);
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
