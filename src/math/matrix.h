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

    ~Matrix()
    {
        delete[] _buffer;
    }

    //
    static Matrix Zeros(int rows, int cols);
    static Matrix Zeros(int size) { return Zeros(size, size); }
    static Matrix Zeros() { return Zeros(4); };

    static Matrix Identity(int size);
    static Matrix Identity() { return Identity(4); };

    static Matrix Translation(float x, float y, float z);
    static Matrix Scaling(float x, float y, float z);
    static Matrix RotationX(float angle);
    static Matrix RotationY(float angle);
    static Matrix RotationZ(float angle);
    static Matrix Shearing(float x_y, float x_z, float y_x, float y_z, float z_x, float z_y);

    //

    int Index(int row, int col) const;
    float At(int row, int col) const;
    void Set(int row, int col, float val);

    Matrix Transpose() const;
    Matrix Submatrix(int row, int col) const;
    Matrix Inverse() const;
    float Minor(int row, int col) const; // Determinant of submatrix
    float Cofactor(int row, int col) const;
    float Determinant() const;

    bool operator==(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    Matrix operator/(const float rhs) const;
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