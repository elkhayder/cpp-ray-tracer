#include <gtest/gtest.h>

#include "../src/physics/ray.h"
#include "../src/math/tuple.h"

TEST(RayTest, Position)
{
    Ray ray(Tuple::Point(2, 3, 4), Tuple::Vector(1, 0, 0));

    EXPECT_EQ(ray.Position(0), Tuple::Point(2, 3, 4));
    EXPECT_EQ(ray.Position(1), Tuple::Point(3, 3, 4));
    EXPECT_EQ(ray.Position(-1), Tuple::Point(1, 3, 4));
    EXPECT_EQ(ray.Position(2.5), Tuple::Point(4.5, 3, 4));
}

TEST(RayTest, IntersectInFront)
{
    Ray ray(Tuple::Point(0, 0, -5), Tuple::Vector(0, 0, 1));
    Sphere sphere;
    auto is = ray.Intersect(sphere);

    EXPECT_EQ(std::get<0>(is), 2);
    EXPECT_FLOAT_EQ(std::get<1>(is).t, 4.0);
    EXPECT_FLOAT_EQ(std::get<2>(is).t, 6.0);

    // Hits
    Intersections xs(sphere);
    xs.Join(std::get<1>(is));
    xs.Join(std::get<2>(is));

    EXPECT_EQ(xs.Hit(), 4);
}

TEST(RayTest, IntersectTangent)
{
    Ray ray(Tuple::Point(0, 1, -5), Tuple::Vector(0, 0, 1));
    Sphere sphere;
    auto is = ray.Intersect(sphere);

    EXPECT_EQ(std::get<0>(is), 2);
    EXPECT_FLOAT_EQ(std::get<1>(is).t, 5.0);
    EXPECT_FLOAT_EQ(std::get<2>(is).t, 5.0);

    // Hits
    Intersections xs(sphere);
    xs.Join(std::get<1>(is));
    xs.Join(std::get<2>(is));

    EXPECT_EQ(xs.Hit(), 5);
}

TEST(RayTest, IntersectNone)
{
    Ray ray(Tuple::Point(0, 2, -5), Tuple::Vector(0, 0, 1));
    Sphere sphere;
    auto is = ray.Intersect(sphere);

    EXPECT_EQ(std::get<0>(is), 0);
}

TEST(RayTest, IntersectInside)
{
    Ray ray(Tuple::Point(0, 0, 0), Tuple::Vector(0, 0, 1));
    Sphere sphere;
    auto is = ray.Intersect(sphere);

    EXPECT_EQ(std::get<0>(is), 2);
    EXPECT_FLOAT_EQ(std::get<1>(is).t, -1.0);
    EXPECT_FLOAT_EQ(std::get<2>(is).t, 1.0);

    // Hits
    Intersections xs(sphere);
    xs.Join(std::get<1>(is));
    xs.Join(std::get<2>(is));

    EXPECT_EQ(xs.Hit(), 1);
}

TEST(RayTest, IntersectBehind)
{
    Ray ray(Tuple::Point(0, 0, 5), Tuple::Vector(0, 0, 1));
    Sphere sphere;
    auto is = ray.Intersect(sphere);

    EXPECT_EQ(std::get<0>(is), 2);
    EXPECT_FLOAT_EQ(std::get<1>(is).t, -6.0);
    EXPECT_FLOAT_EQ(std::get<2>(is).t, -4.0);

    // Hits
    Intersections xs(sphere);
    xs.Join(std::get<1>(is));
    xs.Join(std::get<2>(is));

    EXPECT_EQ(xs.Hit(), std::numeric_limits<float>::max()); // no hits
}

TEST(RayTest, RayTransformation)
{
    Ray r1(Tuple::Point(1, 2, 3), Tuple::Vector(0, 1, 0));

    // Translating
    auto m1 = Matrix::Translation(3, 4, 5);
    auto r2 = r1.Transform(m1);

    EXPECT_EQ(r2.Origin(), Tuple::Point(4, 6, 8));
    EXPECT_EQ(r2.Direction(), Tuple::Vector(0, 1, 0));

    // Scaling
    auto m2 = Matrix::Scaling(2, 3, 4);
    auto r3 = r1.Transform(m2);

    EXPECT_EQ(r3.Origin(), Tuple::Point(2, 6, 12));
    EXPECT_EQ(r3.Direction(), Tuple::Vector(0, 3, 0));
}

TEST(RayTest, ObjectTransformation)
{
    Ray ray(Tuple::Point(0, 0, -5), Tuple::Vector(0, 0, 1));
    Sphere s;

    s.SetTransformation(Matrix::Scaling(2, 2, 2));
    auto is = ray.Intersect(s);

    EXPECT_EQ(std::get<0>(is), 2); // Two intersections
    EXPECT_EQ(std::get<1>(is).t, 3);
    EXPECT_EQ(std::get<2>(is).t, 7);

    s.SetTransformation(Matrix::Translation(5, 0, 0));
    auto is2 = ray.Intersect(s);

    EXPECT_EQ(std::get<0>(is2), 0); // No intersections
}
