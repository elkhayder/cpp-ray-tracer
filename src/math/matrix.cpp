#include "matrix.h"

#include "helpers.h"

Matrix::Matrix(int size)
{
    if (size > 4 || size < 0)
        throw "Invalid matrix size";

    _size = size;
}

Matrix::Matrix(int size, float *data)
{
    if (size > 4 || size < 0)
        throw "Invalid matrix size";

    _size = size;

    // Should I use memcpy ?
    for (int i = 0; i < _size * _size; i++)
    {
        _buffer[i] = data[i];
    }
}

int Matrix::Index(int row, int col) const
{
    if (row >= _size || row < 0 || col >= _size || col < 0)
        throw "Matrix index out of bound";

    return row * _size + col;
}

float Matrix::At(int row, int col) const
{
    return _buffer[Index(row, col)];
}

void Matrix::Set(int row, int col, float val)
{
    _buffer[Index(row, col)] = val;
}

bool operator==(const Matrix &lhs, const Matrix &rhs)
{
    if (lhs._size != rhs._size)
        return false;

    for (int i = 0; i < lhs._size * lhs._size; i++)
    {
        if (!ALMOST_EQ(lhs._buffer[i], rhs._buffer[i]))
            return false;
    }

    return true;
}

Matrix operator*(const Matrix &lhs, const Matrix &rhs)
{
    if (rhs._size != lhs._size)
        throw "Multiplying two matrices with different sizes";

    Matrix result(rhs._size);

    for (int row = 0; row < lhs._size; row++)
    {
        for (int col = 0; col < lhs._size; col++)
        {
            float sum = 0;

            for (int i = 0; i < lhs._size; i++)
            {
                sum += lhs.At(row, i) * rhs.At(i, col);
            }

            result.Set(row, col, sum);
        }
    }

    return result;
}

Tuple Matrix::operator*(const Tuple &tuple)
{
}