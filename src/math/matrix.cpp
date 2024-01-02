#include "matrix.h"

#include "helpers.h"

Matrix::Matrix(int rows, int cols)
{
    if (rows <= 0 || cols <= 0)
        throw "Negative matrix sizes";

    _rows = rows;
    _cols = cols;

    _buffer = new float[rows * cols];
}

Matrix::Matrix(int rows, int cols, float *data) : Matrix(rows, cols)
{
    // Should I use memcpy ?
    for (int i = 0; i < rows * cols; i++)
    {
        _buffer[i] = data[i];
    }

    delete[] data; // TODO : Should it be removed?
}

Matrix::Matrix(const Tuple &tuple) : Matrix(4, 1)
{
    _buffer[0] = tuple.X();
    _buffer[1] = tuple.Y();
    _buffer[2] = tuple.Z();
    _buffer[3] = tuple.W();
}

int Matrix::Index(int row, int col) const
{
    if (row >= _rows || row < 0 || col >= _cols || col < 0)
        throw "Matrix index out of bound";

    return row * _cols + col;
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
    if (lhs._rows != rhs._rows || lhs._cols != rhs._cols)
        return false;

    for (int i = 0; i < lhs._rows * lhs._cols; i++)
    {
        if (!ALMOST_EQ(lhs._buffer[i], rhs._buffer[i]))
            return false;
    }

    return true;
}

Matrix operator*(const Matrix &lhs, const Matrix &rhs)
{
    if (lhs._cols != rhs._rows)
        throw "Multiplying two matrices with incompatible size";

    Matrix result(lhs._rows, rhs._cols);

    for (int row = 0; row < result._rows; row++)
    {
        for (int col = 0; col < result._cols; col++)
        {
            float sum = 0;

            for (int i = 0; i < lhs._cols; i++)
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
    return (Tuple)((*this) * ((Matrix)tuple));
}