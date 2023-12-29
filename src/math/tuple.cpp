#include "tuple.h"

#include <cmath>

float Tuple::Magnitude() const
{
    return std::sqrt(_x * _x + _y * _y + _z * _z + _w * _w);
}

Tuple Tuple::Normalize() const
{
    return *this / Magnitude();
}

float Tuple::Dot(const Tuple &other) const
{
    return _x * other._x + _y * other._y + _z * other._z + _w * other._w;
}

/**
 * Operations
 */

// Cross product
Tuple Tuple::operator*(const Tuple &other) const
{
    return Vector(
        _y * other._z - _z * other._y,
        _z * other._x - _x * other._z,
        _x * other._y - _y * other._x);
}

// Substraction
Tuple Tuple::operator-(const Tuple &other)
{
    /* Add all components */
    return Tuple(
        _x - other._x,
        _y - other._y,
        _z - other._z,
        _w - other._w);
}

// Negation
Tuple Tuple::operator-() const
{
    return Tuple(-_x, -_y, -_z, -_w);
}

// Scalar multiplication (tuple * scalar)
Tuple Tuple::operator*(float scalar) const
{
    return Tuple(
        scalar * _x,
        scalar * _y,
        scalar * _z,
        scalar * _w);
}

Tuple operator+(const Tuple &a, const Tuple &b)
{
    return Tuple(
        a._x + b._x,
        a._y + b._y,
        a._z + b._z,
        a._w + b._w);
    ;
}

// Scalar division
Tuple Tuple::operator/(float scalar) const
{
    return Tuple(
        _x / scalar,
        _y / scalar,
        _z / scalar,
        _w / scalar);
}

Tuple operator*(float scalar, const Tuple &tuple)
{
    return tuple * scalar;
}