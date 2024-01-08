#ifndef __RAY_H
#define __RAY_H

#include "../math/tuple.h"
#include "../math/matrix.h"
#include "objects/sphere.h"

#include "intersections.h"

class Ray
{
public:
    Ray(Tuple origin, Tuple direction) : _origin(origin), _direction(direction) {}

    Tuple Position(float t) const;

    Ray Transform(Matrix matrix) const;

    std::tuple<int, Intersection, Intersection> Intersect(const Sphere &sphere);

    const Tuple &Origin() const
    {
        return _origin;
    }

    const Tuple &Direction() const
    {
        return _direction;
    }

private:
    Tuple _origin,
        _direction;
};

#endif // __RAY_H