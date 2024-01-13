#include <gtest/gtest.h>

#include <cmath>

#include "../src/physics/objects/sphere.h"

TEST(SphereTest, Normal)
{
    Sphere s;

    EXPECT_EQ(
        s.NormalAt(Tuple::Point(1, 0, 0)),
        Tuple::Vector(1, 0, 0));

    EXPECT_EQ(
        s.NormalAt(Tuple::Point(0, 1, 0)),
        Tuple::Vector(0, 1, 0));

    EXPECT_EQ(
        s.NormalAt(Tuple::Point(0, 0, 1)),
        Tuple::Vector(0, 0, 1));

    EXPECT_EQ(
        s.NormalAt(Tuple::Point(std::sqrt(3) / 3, std::sqrt(3) / 3, std::sqrt(3) / 3)),
        Tuple::Vector(std::sqrt(3) / 3, std::sqrt(3) / 3, std::sqrt(3) / 3));

    // Add trasnformation
    s.SetTransformation(Matrix::Translation(0, 1, 0));

    EXPECT_EQ(
        s.NormalAt(Tuple::Point(0, 1.70711, -0.70711)),
        Tuple::Vector(0, 0.70711, -0.70711));

    // Add trasnformation
    s.SetTransformation(Matrix::Scaling(1, 0.5, 1) * Matrix::RotationZ(std::numbers::pi / 5));

    EXPECT_EQ(
        s.NormalAt(Tuple::Point(0, std::sqrt(2) / 2, -std::sqrt(2) / 2)),
        Tuple::Vector(0, 0.97014, -0.24254));
}
