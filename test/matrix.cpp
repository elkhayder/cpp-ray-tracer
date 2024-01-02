#include <gtest/gtest.h>

#include "../src/math/matrix.h"

TEST(MatrixTest, Equality)
{

    // clang-format off
    // TODO : Fix memory leakage
    Matrix m(4, new float[]{
        1, 2, 3, 4, //
        1, 2, 3, 4, //
        1, 2, 3, 4, //
        1, 2, 3, 4 //
    });
    // clang-format on

    EXPECT_EQ(m, m);
}

TEST(MatrixTest, Multiplication)
{
    // clang-format off
    EXPECT_EQ(
        Matrix(4, new float[]{
            1, 2, 3, 4, //
            5, 6, 7, 8,  //
            9, 8, 7, 6, //
            5, 4, 3, 2 //
        }) * Matrix(4, new float[]{
            -2, 1, 2, 3, //
            3, 2, 1, -1, //
            4, 3, 6, 5, //
            1, 2, 7, 8 //
        }), Matrix(4, new float[]{
            20, 22, 50, 48, //
            44, 54, 114, 108, //
            40, 58, 110, 102, //
            16, 26, 46, 42 //
        })
    );
    // clang-format on
}

TEST(MatrixTest, FromTuple)
{
    EXPECT_EQ(
        (Matrix)Tuple::Vector(1, 2, 3),
        Matrix(4, 1, new float[]{1, 2, 3, 0}));
}