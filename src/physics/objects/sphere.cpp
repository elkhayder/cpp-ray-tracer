#include "sphere.h"

void Sphere::SetTransformation(const Matrix &matrix)
{
    _transformation = matrix;
    _inverseTransformation = matrix.Inverse();
}

const Matrix &Sphere::Transformation() const
{
    return _transformation;
}

const Matrix &Sphere::InverseTransformation() const
{
    return _inverseTransformation;
}

bool Sphere::operator==(const Sphere &other)
{
    return this == &other;
}

Tuple Sphere::NormalAt(const Tuple &world_point) const
{
    auto objectPoint = _inverseTransformation * world_point;
    auto objectNormal = objectPoint - Tuple::Point(0, 0, 0);
    auto worldNormal = _inverseTransformation.Transpose() * objectNormal;
    worldNormal.SetW(0);
    return worldNormal.Normalize();
}