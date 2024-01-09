#ifndef __SPHERE_H
#define __SPHERE_H

#include "../../math/tuple.h"
#include "../../math/matrix.h"

class Sphere
{
public:
    Sphere(Tuple origin) : _origin(origin) {}
    Sphere() : Sphere(Tuple::Point(0, 0, 0)) {}

    void SetTransformation(const Matrix &matrix);

    const Matrix &Transformation() const;
    const Matrix &InverseTransformation() const;

    Tuple NormalAt(const Tuple &point) const;

    bool operator==(const Sphere &other);

private:
    Tuple _origin;
    Matrix _transformation = Matrix::Identity(), _inverseTransformation = Matrix::Identity();
};

#endif // __SPHERE_H