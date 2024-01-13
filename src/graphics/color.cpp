#include "color.h"

#include "../math/helpers.h"

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

Color Color::operator*(const float &scalar) const
{
    return Color(_r * scalar, _g * scalar, _b * scalar);
}

bool Color::operator==(const Color &other) const
{
    return ALMOST_EQ(_r, other._r) && ALMOST_EQ(_g, other._g) && ALMOST_EQ(_b, other._b);
}