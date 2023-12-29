#ifndef __MATRIX_H
#define __MATRIX_H

#include "tuple.h"

class Matrix
{
public:
    Matrix(int size);

    int Index(int row, int col) const;
    float At(int row, int col) const;
    void Set(int row, int col, float val);

    friend bool operator==(const Matrix &lhs, const Matrix &rhs);
    friend Matrix operator*(const Matrix &lhs, const Matrix &rhs);
    Tuple operator*(const Tuple &tuple);

private:
    int _size;
    float _buffer[4 * 4] = {}; // MAX 4*4 matrix
};

#endif // __MATRIX_H