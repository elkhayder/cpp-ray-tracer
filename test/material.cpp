#include <gtest/gtest.h>

#include <cmath>
#include "../src/graphics/material.h"
#include "../src/math/tuple.h"

TEST(MaterialTest, LightingInFront)
{
    Material material;
    Tuple position = Tuple::Point(0, 0, 0);
    Tuple normalV = Tuple::Vector(0, 0, -1);
    Tuple eyeV = Tuple::Vector(0, 0, -1);
    Light light(Tuple::Point(0, 0, -10), Color(1, 1, 1));

    EXPECT_EQ(material.Lighting(light, position, eyeV, normalV),
              Color(1.9, 1.9, 1.9));
}

TEST(MaterialTest, LightingEye45Offset)
{
    Material material;
    Tuple position = Tuple::Point(0, 0, 0);
    Tuple normalV = Tuple::Vector(0, 0, -1);
    Tuple eyeV = Tuple::Vector(0, std::sqrt(2) / 2, -std::sqrt(2) / 2);
    Light light(Tuple::Point(0, 0, -10), Color(1, 1, 1));

    EXPECT_EQ(material.Lighting(light, position, eyeV, normalV),
              Color(1, 1, 1));
}

TEST(MaterialTest, LightingLightSunBoth45Offset)
{
    Material material;
    Tuple position = Tuple::Point(0, 0, 0);
    Tuple normalV = Tuple::Vector(0, 0, -1);
    Tuple eyeV = Tuple::Vector(0, -std::sqrt(2) / 2, -std::sqrt(2) / 2);
    Light light(Tuple::Point(0, 10, -10), Color(1, 1, 1));

    EXPECT_EQ(material.Lighting(light, position, eyeV, normalV),
              Color(1.6364, 1.6364, 1.6364));
}

TEST(MaterialTest, LightingLight45Offset)
{
    Material material;
    Tuple position = Tuple::Point(0, 0, 0);
    Tuple normalV = Tuple::Vector(0, 0, -1);
    Tuple eyeV = Tuple::Vector(0, -std::sqrt(2) / 2, -std::sqrt(2) / 2);
    Light light(Tuple::Point(0, 0, 10), Color(1, 1, 1));

    EXPECT_EQ(material.Lighting(light, position, eyeV, normalV),
              Color(0.1, 0.1, 0.1));
}