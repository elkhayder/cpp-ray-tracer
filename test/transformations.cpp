#include <gtest/gtest.h>

#include <cmath>
#include <numbers>

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

TEST(Transformations, Scaling)
{
    EXPECT_EQ( // Point
        Matrix::Scaling(2, 3, 4) * Tuple::Point(-4, 6, 8),
        Tuple::Point(-8, 18, 32));

    EXPECT_EQ( // Vector
        Matrix::Scaling(2, 3, 4) * Tuple::Vector(-4, 6, 8),
        Tuple::Vector(-8, 18, 32));
}

TEST(Transformations, RotationX)
{
    EXPECT_EQ(
        Matrix::RotationX(std::numbers::pi / 4) * Tuple::Point(0, 1, 0),
        Tuple::Point(0, std::sqrt(2) / 2, std::sqrt(2) / 2));

    EXPECT_EQ(
        Matrix::RotationX(std::numbers::pi / 2) * Tuple::Point(0, 1, 0),
        Tuple::Point(0, 0, 1));

    EXPECT_EQ(
        Matrix::RotationX(std::numbers::pi / 4).Inverse() * Tuple::Point(0, 1, 0),
        Tuple::Point(0, std::sqrt(2) / 2, -std::sqrt(2) / 2));
}

TEST(Transformations, RotationY)
{
    EXPECT_EQ(
        Matrix::RotationY(std::numbers::pi / 4) * Tuple::Point(0, 0, 1),
        Tuple::Point(std::sqrt(2) / 2, 0, std::sqrt(2) / 2));

    EXPECT_EQ(
        Matrix::RotationY(std::numbers::pi / 2) * Tuple::Point(0, 0, 1),
        Tuple::Point(1, 0, 0));
}

TEST(Transformations, RotationZ)
{
    EXPECT_EQ(
        Matrix::RotationZ(std::numbers::pi / 4) * Tuple::Point(0, 1, 0),
        Tuple::Point(-std::sqrt(2) / 2, std::sqrt(2) / 2, 0));

    EXPECT_EQ(
        Matrix::RotationZ(std::numbers::pi / 2) * Tuple::Point(0, 1, 0),
        Tuple::Point(-1, 0, 0));
}

TEST(Transformations, Shearing)
{
    EXPECT_EQ(
        Matrix::Shearing(1, 0, 0, 0, 0, 0) * Tuple::Point(2, 3, 4),
        Tuple::Point(5, 3, 4));

    EXPECT_EQ(
        Matrix::Shearing(0, 1, 0, 0, 0, 0) * Tuple::Point(2, 3, 4),
        Tuple::Point(6, 3, 4));

    EXPECT_EQ(
        Matrix::Shearing(0, 0, 1, 0, 0, 0) * Tuple::Point(2, 3, 4),
        Tuple::Point(2, 5, 4));

    EXPECT_EQ(
        Matrix::Shearing(0, 0, 0, 1, 0, 0) * Tuple::Point(2, 3, 4),
        Tuple::Point(2, 7, 4));

    EXPECT_EQ(
        Matrix::Shearing(0, 0, 0, 0, 1, 0) * Tuple::Point(2, 3, 4),
        Tuple::Point(2, 3, 6));

    EXPECT_EQ(
        Matrix::Shearing(0, 0, 0, 0, 0, 1) * Tuple::Point(2, 3, 4),
        Tuple::Point(2, 3, 7));
}