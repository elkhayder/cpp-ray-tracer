#include <gtest/gtest.h>

#include "../src/math/matrix.h"

TEST(MatrixTest, Equality)
{

    // clang-format off
    // TODO : Fix memory leakage
    Matrix m(4, new float[16]{
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
        Matrix(4, new float[16]{
            1, 2, 3, 4, //
            5, 6, 7, 8,  //
            9, 8, 7, 6, //
            5, 4, 3, 2 //
        }) * Matrix(4, new float[16]{
            -2, 1, 2, 3, //
            3, 2, 1, -1, //
            4, 3, 6, 5, //
            1, 2, 7, 8 //
        }), Matrix(4, new float[16]{
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
        Matrix(4, 1, new float[4]{1, 2, 3, 0}));
}

TEST(MatrixTest, IdentityMatrixConstructor)
{
    EXPECT_EQ(
        Matrix::Identity(2),
        // clang-format off
        Matrix(2, new float[4]{
            1, 0,
            0, 1
        })
        // clang-format on
    );

    EXPECT_EQ(
        Matrix::Identity(), // Default size = 4
        // clang-format off
        Matrix(4, new float[16]{
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1,
        })
        // clang-format on
    );
}

TEST(MatrixTest, Transpose)
{
    EXPECT_EQ( // Identity Matrix transposing does nothing
        Matrix::Identity().Transpose(),
        Matrix::Identity());

    // Transposing Square Matrix
    EXPECT_EQ(
        // clang-format off
        Matrix(4, new float[16]{
            0, 9, 3, 0,
            9, 8, 0, 8,
            1, 8, 5, 3,
            0, 0, 5, 8
        }).Transpose(),
        Matrix(4, new float[16]{
            0, 9, 1, 0,
            9, 8, 8, 0,
            3, 0, 5, 5,
            0, 8, 3, 8
        })
        // clang-format on
    );

    // Transposing non Square Matrix
    EXPECT_EQ(
        // clang-format off
        Matrix(2, 4, new float[8]{
            0, 9, 3, 0,
            9, 8, 0, 8,
        }).Transpose(),
        Matrix(4, 2, new float[8]{
            0, 9,
            9, 8,
            3, 0,
            0, 8
        })
        // clang-format on
    );
}

TEST(MatrixTest, Submatrix)
{
    EXPECT_EQ(
        // clang-format off
        Matrix(3, new float[9]{
             1, 5,  0, 
            -3, 2,  7,
             0, 6, -3
        }).Submatrix(0, 2),
        Matrix(2, new float[4]{
            -3, 2,
             0, 6
        })
        // clang-format on
    );

    EXPECT_EQ(
        // clang-format off
        Matrix(4, new float[16]{
            -6, 1, 1, 6, 
            -8, 5, 8, 6, 
            -1, 0, 8, 2, 
            -7, 1, -1, 1
        }).Submatrix(2, 1),
        Matrix(3, new float[9]{
            -6, 1, 6, 
            -8, 8, 6, 
            -7, -1, 1
        })
        // clang-format on
    );
}
