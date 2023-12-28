#ifndef __PROJECTILE_H
#define __PROJECTILE_H

#include "math/tuple.h"

class Environment;

class Projectile
{
public:
    Projectile(Tuple position, Tuple velocity) : _position(position), _velocity(velocity) {}

    Tuple Position() const
    {
        return _position;
    }

    Tuple Velocity() const
    {
        return _velocity;
    }

    friend class Environment;

private:
    Tuple _position; // Point
    Tuple _velocity; // Vector
};

#endif // __PROJECTILE_H