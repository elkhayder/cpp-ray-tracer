#include "canvas.h"

#include <fstream>

#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)

int Canvas::GetIndex(int x, int y) const
{
    return (_height - y) * _width + x;
}

void Canvas::WritePixel(int x, int y, Color color)
{
    if (x >= _width || x < 0 || y >= _height || y < 0)
        return; // Ignore points outside the canvas

    _buffer[GetIndex(x, y)] = color;
}

Color Canvas::GetPixel(int x, int y) const
{
    return _buffer[GetIndex(x, y)];
}

bool Canvas::Save(std::string filename) const
{
    std::ofstream outputFile;

    outputFile.open(filename, std::ios::out);

    if (!outputFile.is_open())
        return false;

    outputFile << "P3" << std::endl;
    outputFile << _width << " " << _height << std::endl;
    outputFile << 255 << std::endl;

    for (int i = 0; i < _width * _height; i++)
    {
        Color c = _buffer[i];

        outputFile << (int)(MIN(c.R(), 1) * 255) << " " << (int)(MIN(c.G(), 1) * 255) << " " << (int)(MIN(c.B(), 1) * 255) << std::endl;
    }

    outputFile.close();

    return true;
}