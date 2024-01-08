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