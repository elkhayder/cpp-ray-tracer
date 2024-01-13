#ifndef __SPHERE_H
#define __SPHERE_H

#include "../../math/tuple.h"
#include "../../math/matrix.h"
#include "../../graphics/material.h"

class Sphere
{
public:
    Sphere() {}
    Sphere(Material material) : material(material) {}

    void SetTransformation(const Matrix &matrix);

    const Matrix &Transformation() const;
    const Matrix &InverseTransformation() const;

    Tuple NormalAt(const Tuple &point) const;

    bool operator==(const Sphere &other);

public:
    Material material;

private:
    Matrix _transformation = Matrix::Identity(), _inverseTransformation = Matrix::Identity();
};

#endif // __SPHERE_H