#ifndef __LIGHT_H
#define __LIGHT_H

#include "../graphics/color.h"
#include "../math/tuple.h"

class Light
{
public:
    Light(Color intensity, Tuple position) : _intensity(intensity),
                                             _position(position) {}

private:
    Color _intensity;
    Tuple _position;
};

#endif // __LIGHT_H