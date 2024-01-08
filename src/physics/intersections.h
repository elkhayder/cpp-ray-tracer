#ifndef __INTERSECTIONS_H
#define __INTERSECTIONS_H

#include <vector>
#include <memory>
#include <limits>

#include "objects/sphere.h"

typedef struct
{
    std::shared_ptr<Sphere> object;
    float t;
} Intersection;

class Intersections
{
public:
    Intersections(const Sphere &sphere);

    void Join(const Intersection &other);

    int Count() const;

    float Hit() const;

    float operator[](int idx) const;

private:
    std::vector<float> _values;
    std::shared_ptr<Sphere> _object;
    float _hit = std::numeric_limits<float>::max(); // Start with a negative value,  it will be replaced later
};

#endif // __INTERSECTIONS_H