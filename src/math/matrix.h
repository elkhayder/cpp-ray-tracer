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

    int Index(int row, int col) const;
    float At(int row, int col) const;
    void Set(int row, int col, float val);

    friend bool operator==(const Matrix &lhs, const Matrix &rhs);
    friend Matrix operator*(const Matrix &lhs, const Matrix &rhs);
    Tuple operator*(const Tuple &tuple);

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