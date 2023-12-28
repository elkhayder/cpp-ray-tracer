#ifndef __CANVAS_H
#define __CANVAS_H

#include "color.h"
#include <string>

class Canvas
{
public:
    Canvas(int width, int height) : _width(width), _height(height)
    {
        _buffer = new Color[_width * _height];
    }

    ~Canvas()
    {
        delete[] _buffer;
    }

    int GetIndex(int x, int y) const;

    void WritePixel(int x, int y, Color color);

    Color GetPixel(int x, int y) const;

    // TODO : provide multiple saving methods (move it oustside?)
    bool Save(std::string filename) const;

    int Width() const
    {
        return _width;
    }

    int Height() const
    {
        return _height;
    }

private:
    const int _width, _height;
    Color *_buffer;
};

#endif // __CANVAS_H