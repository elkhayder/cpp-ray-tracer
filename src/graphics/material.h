#ifndef __MATERIAL_H
#define __MATERIAL_H

#include "color.h"
#include "../physics/light.h"

class Material
{
public:
    Material() : Material(Color(1, 1, 1), 0.1, 0.9, 0.9, 200) {}
    Material(Color color, float ambient, float diffuse, float specular, float shininess)
        : _color(color),
          _ambient(ambient),
          _diffuse(diffuse),
          _specular(specular),
          _shininess(shininess) {}

    Color Lighting(const Light &light,
                   const Tuple &point,
                   const Tuple &eye,
                   const Tuple &normal) const;

private:
    Color _color;
    float _ambient, _diffuse, _specular, _shininess;
};

#endif // __MATERIAL_H