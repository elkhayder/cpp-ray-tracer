#include "color.h"

Color Color::operator+(const Color &other) const
{
    return Color(_r + other._r, _g + other._g, _b + other._b);
}

Color Color::operator-(const Color &other) const
{
    return Color(_r - other._r, _g - other._g, _b - other._b);
}

Color Color::operator*(const Color &other) const
{
    return Color(_r * other._r, _g * other._g, _b * other._b);
}