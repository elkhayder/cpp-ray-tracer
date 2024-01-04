#include "matrix.h"

#include <assert.h>

#include "helpers.h"

Matrix::Matrix(int rows, int cols)
{
    assert(cols > 0 && rows > 0);

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
    assert(row < _rows && row >= 0 && col < _cols && col >= 0);

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

bool Matrix::operator==(const Matrix &rhs) const
{
    if (_rows != rhs._rows || _cols != rhs._cols)
        return false;

    for (int i = 0; i < _rows * _cols; i++)
    {
        if (!ALMOST_EQ(_buffer[i], rhs._buffer[i]))
            return false;
    }

    return true;
}

Matrix Matrix::operator*(const Matrix &rhs) const
{
    assert(_cols == rhs._rows);

    Matrix result(_rows, rhs._cols);

    for (int row = 0; row < result._rows; row++)
    {
        for (int col = 0; col < result._cols; col++)
        {
            float sum = 0;

            for (int i = 0; i < _cols; i++)
            {
                sum += At(row, i) * rhs.At(i, col);
            }

            result.Set(row, col, sum);
        }
    }

    return result;
}

Matrix Matrix::operator/(const float coef) const
{

    Matrix result(_rows, _cols);

    for (int row = 0; row < result._rows; row++)
        for (int col = 0; col < result._cols; col++)
            result.Set(row, col, At(row, col) / coef);

    return result;
}

Tuple Matrix::operator*(const Tuple &tuple) const
{
    return static_cast<Tuple>((*this) * static_cast<Matrix>(tuple));
}

Matrix Matrix::Transpose() const
{
    Matrix result(_cols, _rows); // Flipped rows and cols

    for (int i = 0; i < _rows; i++)
    {
        for (int j = 0; j < _cols; j++)
        {
            result.Set(j, i, At(i, j));
        }
    }

    return result;
}

Matrix Matrix::Submatrix(int row, int col) const
{
    assert(_rows >= 2 && _cols >= 2); // Have at least a 2x2 matrix

    Matrix result(_rows - 1, _cols - 1);

    for (int i = 0; i < _rows; i++)
    {
        if (i == row)
            continue; // Skip row
        for (int j = 0; j < _cols; j++)
        {
            if (j == col)
                continue; // Skip col

            int x = i > row ? i - 1 : i;
            int y = j > col ? j - 1 : j;

            result.Set(x, y, At(i, j));
        }
    }

    return result;
}

float Matrix::Minor(int row, int col) const
{
    return Submatrix(row, col).Determinant();
}

float Matrix::Cofactor(int row, int col) const
{
    if (row % 2 == col % 2) // XOR
    {
        return Minor(row, col);
    }

    return -Minor(row, col);
}

float Matrix::Determinant() const
{
    assert(_rows == _cols); // Determinant is computable only for square matrices

    if (_rows == 2)
    {
        return _buffer[0] * _buffer[3] - _buffer[1] * _buffer[2]; // ad - bc
    }

    float det = 0;
    for (int col = 0; col < _cols; col++)
    {
        det += At(0, col) * Cofactor(0, col);
    }

    return det;
}

Matrix Matrix::Inverse() const
{
    float det = Determinant(); // This takes care of verifying it is a square matrix

    assert(det != 0.0);

    Matrix cofactors(_rows);

    for (int i = 0; i < _rows; i++)
        for (int j = 0; j < _cols; j++)
            cofactors.Set(i, j, Cofactor(i, j));

    return cofactors.Transpose() / det;
}

//

Matrix Matrix::Zeros(int rows, int cols)
{
    Matrix result(rows, cols);

    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            result.Set(row, col, 0);

    return result;
}

Matrix Matrix::Identity(int size)
{
    Matrix result = Matrix::Zeros(size);

    for (int i = 0; i < size; i++)
        result.Set(i, i, 1);

    return result;
}

Matrix Matrix::Translation(float x, float y, float z)
{
    Matrix result = Matrix::Identity();

    result.Set(0, 3, x);
    result.Set(1, 3, y);
    result.Set(2, 3, z);

    return result;
}