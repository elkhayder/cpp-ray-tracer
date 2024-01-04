#ifndef __MATRIX_H
#define __MATRIX_H

#include "tuple.h"

class Matrix
{
public:
    Matrix(const Tuple &tuple);
    Matrix(int size) : Matrix(size, size) {}
    Matrix(int size, float *data) : Matrix(size, size, data){};
    Matrix(int rows, int cols);
    Matrix(int rows, int cols, float *data);

    static Matrix Identity();
    static Matrix Identity(int size);

    ~Matrix()
    {
        delete[] _buffer;
    }

    int Index(int row, int col) const;
    float At(int row, int col) const;
    void Set(int row, int col, float val);

    Matrix Transpose() const;
    // Row and Col are 0 indexed
    Matrix Submatrix(int row, int col) const;

    bool operator==(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    Tuple operator*(const Tuple &tuple) const;

    int Rows() const
    {
        return _rows;
    }

    int Cols() const
    {
        return _cols;
    }

private:
    int _rows, _cols;
    float *_buffer;
};

#endif // __MATRIX_H