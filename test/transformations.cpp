#include <gtest/gtest.h>

#include "../src/math/matrix.h"
#include "../src/math/tuple.h"

TEST(Transformations, Translation)
{
    EXPECT_EQ(
        Matrix::Translation(5, -3, 2) * Tuple::Point(-3, 4, 5),
        Tuple::Point(2, 1, 7));

    EXPECT_EQ(
        Matrix::Translation(5, -3, 2).Inverse() * Tuple::Point(-3, 4, 5),
        Tuple::Point(-8, 7, 3));

    // Vectors are not affected
    EXPECT_EQ(
        Matrix::Translation(5, -3, 2) * Tuple::Vector(-3, 4, 5),
        Tuple::Vector(-3, 4, 5));
}