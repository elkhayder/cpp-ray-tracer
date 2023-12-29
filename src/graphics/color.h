#ifndef __COLOR_H
#define __COLOR_H

class Color
{
public:
    Color() : _r(0), _g(0), _b(0) {}
    Color(float r, float g, float b) : _r(r), _g(g), _b(b) {}

    /**
     * Operations
     */

    Color operator+(const Color &other) const;

    Color operator-(const Color &other) const;

    Color operator*(const Color &other) const;

    /**
     * Comparison
     */

    bool operator==(const Color &other) const;

    float R() const
    {
        return _r;
    }

    float G() const
    {
        return _g;
    }

    float B() const
    {
        return _b;
    }

private:
    float _r, _g, _b;
};

#endif // __COLOR_H