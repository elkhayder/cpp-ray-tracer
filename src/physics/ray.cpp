#include "ray.h"

#include <cmath>

Tuple Ray::Position(float t) const
{
    return _origin + _direction * t;
}

Ray Ray::Transform(Matrix matrix) const
{
    return Ray(
        matrix * _origin,
        matrix * _direction);
}

std::tuple<int, Intersection, Intersection> Ray::Intersect(const Sphere &sphere)
{
    Ray objectSpaceRay = Transform(sphere.InverseTransformation());

    Tuple sphereToRay = objectSpaceRay._origin - Tuple::Point(0, 0, 0);

    float a = objectSpaceRay._direction.Dot(objectSpaceRay._direction);
    float b = 2.0 * objectSpaceRay._direction.Dot(sphereToRay);
    float c = sphereToRay.Dot(sphereToRay) - 1;

    float discriminant = b * b - 4 * a * c;

    if (discriminant >= 0)
    {
        return std::make_tuple(
            2,
            Intersection{
                .object = std::make_shared<Sphere>(sphere),
                .t = (-b - std::sqrt(discriminant)) / (2 * a),
            },
            Intersection{
                .object = std::make_shared<Sphere>(sphere),
                .t = (-b + std::sqrt(discriminant)) / (2 * a),
            });
    }

    // No hits
    return std::make_tuple(
        0,
        Intersection{},
        Intersection{});
}