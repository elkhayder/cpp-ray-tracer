#include "intersections.h"

#include <assert.h>

Intersections::Intersections(const Sphere &sphere)
{
    _object = std::make_shared<Sphere>(sphere);
}

void Intersections::Join(const Intersection &intersection)
{
    // Compare the two object pointers, they should be equal and not null
    assert(_object.get() == nullptr || _object.get() != intersection.object.get());

    _values.push_back(intersection.t);

    if (intersection.t >= 0 && intersection.t < _hit)
        _hit = intersection.t;
}

int Intersections::Count() const
{
    return _values.size();
}

float Intersections::Hit() const
{
    return _hit;
}

float Intersections::operator[](int idx) const
{
    return _values[idx];
}