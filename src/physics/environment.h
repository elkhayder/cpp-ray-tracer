#ifndef __ENVIRONMENT_H
#define __ENVIRONMENT_H

#include "math/tuple.h"
#include "projectile.h"

class Environment
{
public:
    Environment(Tuple gravity, Tuple wind) : _gravity(gravity), _wind(wind) {}

    Projectile Tick(const Projectile &projectile) const;

    Tuple Gravity() const
    {
        return _gravity;
    }

    Tuple Wind() const
    {
        return _wind;
    }

public:
    Tuple _gravity, _wind; // Vector
};

#endif // __ENVIRONMENT_H