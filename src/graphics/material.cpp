#include "material.h"

#include <cmath>

Color Material::Lighting(const Light &light,
                         const Tuple &point,
                         const Tuple &eye,
                         const Tuple &normal) const
{
    Color diffuse, specular, ambient;

    Color effectiveColor = _color * light.intensity;
    Tuple lightVector = (light.position - point).Normalize();
    ambient = effectiveColor * _ambient;

    // light_dot_normal represents the cosine of the angle between the
    // light vector and the normal vector. A negative number means the
    // light is on the other side of the surface.
    float lightDotNormal = lightVector.Dot(normal);

    if (lightDotNormal < 0)
    {
        diffuse = Color(0, 0, 0);  // Black
        specular = Color(0, 0, 0); // Black
    }
    else
    {
        diffuse = effectiveColor * _diffuse * lightDotNormal;

        // reflect_dot_eye represents the cosine of the angle between the
        // reflection vector and the eye vector. A negative number means the
        // light reflects away from the eye.
        Tuple reflectV = (-lightVector).Reflect(normal);
        float reflectDotEye = reflectV.Dot(eye);

        if (reflectDotEye <= 0)
            specular = Color(0, 0, 0); // Black
        else
        { // compute the specular contribution
            float factor = std::pow(reflectDotEye, _shininess);
            specular = light.intensity * _specular * factor;
        }
    }

    return ambient + diffuse + specular;
}