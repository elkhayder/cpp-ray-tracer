#include <ostream>
#ifndef __TUPLE_H
#define __TUPLE_H

class Tuple
{
public:
    Tuple(float x, float y, float z, float w) : _x(x), _y(y), _z(z), _w(w){};

    static Tuple Vector(float x, float y, float z)
    {
        return Tuple(x, y, z, 0.0);
    }

    static Tuple Point(float x, float y, float z)
    {
        return Tuple(x, y, z, 1.0);
    }

    float Magnitude() const;
    Tuple Normalize() const;
    float Dot(const Tuple &other) const;

    float X() const
    {
        return _x;
    }

    float Y() const
    {
        return _y;
    }

    float Z() const
    {
        return _z;
    }

    /**
     * Operations
     */

    // Cross product
    Tuple operator*(const Tuple &other) const;

    // Addition
    friend Tuple operator+(const Tuple &a, const Tuple &b)
    {
        return Tuple(
            a._x + b._x,
            a._y + b._y,
            a._z + b._z,
            a._w + b._w);
        ;
    };

    // Substraction
    Tuple operator-(const Tuple &other);

    // Negation
    Tuple operator-() const;

    // Scalar division
    Tuple operator/(float scalar) const;

    // Scalar multiplication (tuple * scalar)
    Tuple operator*(float scalar) const;

    // Scalar multiplication (scalar * tuple)
    friend Tuple operator*(float scalar, const Tuple &tuple)
    {
        return tuple * scalar;
    };

    /**
     * Output stream
     */

    friend std::ostream &operator<<(std::ostream &os, const Tuple &t)
    {
        return os << ((t._w == 0) ? "Point" : "Vector") << "(" << t._x << ", " << t._y << ", " << t._z << ")";
    }

private:
    float _x, _y, _z, _w;
};

#endif // __TUPLE_H