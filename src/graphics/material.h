#ifndef __MATERIAL_H
#define __MATERIAL_H

#include "color.h"
#include "../physics/light.h"

class Material
{
public:
    Material() : Material(Color(1, 1, 1), 0.1, 0.9, 0.9, 200) {}
    Material(Color color, float ambient, float diffuse, float specular, float shininess)
        : color(color),
          ambient(ambient),
          diffuse(diffuse),
          specular(specular),
          shininess(shininess) {}

    Color Lighting(const Light &light,
                   const Tuple &point,
                   const Tuple &eye,
                   const Tuple &normal) const;

public:
    Color color;
    float ambient, diffuse, specular, shininess;
};

#endif // __MATERIAL_H