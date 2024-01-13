#ifndef __LIGHT_H
#define __LIGHT_H

#include "../graphics/color.h"
#include "../math/tuple.h"

class Light
{
public:
    Light(Tuple position, Color intensity) : position(position),
                                             intensity(intensity) {}

public:
    Color intensity;
    Tuple position;
};

#endif // __LIGHT_H