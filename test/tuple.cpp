#include <gtest/gtest.h>

#include <cmath>
#include "../src/math/tuple.h"

TEST(TupleTest, Equality)
{
    EXPECT_EQ(Tuple(5, 6, 7, 8), Tuple(5, 6, 7, 8));
}

TEST(TupleTest, Addition)
{
    EXPECT_EQ(
        Tuple::Vector(3, -2, 5) + Tuple::Point(-2, 3, 1),
        Tuple::Point(1, 1, 6));
}

TEST(TupleTest, Subtraction)
{
    // Point - Point
    EXPECT_EQ(
        Tuple::Point(3, 2, 1) - Tuple::Point(5, 6, 7),
        Tuple::Vector(-2, -4, -6));

    // Point - Vector
    EXPECT_EQ(
        Tuple::Point(3, 2, 1) - Tuple::Vector(5, 6, 7),
        Tuple::Point(-2, -4, -6));

    // Vector - Vector
    EXPECT_EQ(
        Tuple::Vector(3, 2, 1) - Tuple::Vector(5, 6, 7),
        Tuple::Vector(-2, -4, -6));
}

TEST(TupleTest, Negation)
{
    EXPECT_EQ(
        -Tuple::Vector(1, -2, 3),
        Tuple::Vector(-1, 2, -3));
}

TEST(TupleTest, ScalarMultiplication)
{
    EXPECT_EQ(
        3.5 * Tuple(1, -2, 3, -4),
        Tuple(3.5, -7, 10.5, -14));

    EXPECT_EQ(
        0.5 * Tuple(1, -2, 3, -4),
        Tuple(0.5, -1, 1.5, -2));
}

TEST(TupleTest, ScalarDivision)
{
    EXPECT_EQ(
        Tuple(1, -2, 3, -4) / 2,
        Tuple(0.5, -1, 1.5, -2));
}

TEST(TupleTest, Magnitude)
{
    EXPECT_EQ(
        Tuple::Vector(1, 0, 0).Magnitude(),
        1);

    EXPECT_FLOAT_EQ(
        Tuple::Vector(1, 2, 3).Magnitude(),
        std::sqrt(14));
}

TEST(TupleTest, Normalization)
{
    EXPECT_EQ(
        Tuple::Vector(1, 2, 3).Normalize(),
        Tuple::Vector(0.26726, 0.53452, 0.80178));
}

TEST(TupleTest, DotProduct)
{
    EXPECT_EQ(
        Tuple::Vector(1, 2, 3).Dot(Tuple::Vector(2, 3, 4)),
        20);
}

TEST(TupleTest, CrossProduct)
{
    Tuple a = Tuple::Vector(1, 2, 3);
    Tuple b = Tuple::Vector(2, 3, 4);

    Tuple c = Tuple::Vector(-1, 2, -1);

    EXPECT_EQ(a * b, c);

    EXPECT_EQ(b * a, -c);
}

TEST(TupleTest, Reflect)
{
    EXPECT_EQ(
        Tuple::Vector(1, -1, 0).Reflect(Tuple::Vector(0, 1, 0)),
        Tuple::Vector(1, 1, 0));

    EXPECT_EQ(
        Tuple::Vector(0, -1, 0).Reflect(Tuple::Vector(std::sqrt(2) / 2, std::sqrt(2) / 2, 0)),
        Tuple::Vector(1, 0, 0));
}