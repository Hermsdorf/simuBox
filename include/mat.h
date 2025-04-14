#include <cmath>

namespace mat
{
    double rotate(double x, double y, double angle)
    {
        double rad = angle * M_PI / 180.0;
        return x * cos(rad) - y * sin(rad);
    }
}