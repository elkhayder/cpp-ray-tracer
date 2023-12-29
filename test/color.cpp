#include <gtest/gtest.h>

#include "../src/graphics/color.h"

TEST(ColorTest, Equality)
{
    EXPECT_EQ(Color(0.1, 0.1, 0.1), Color(0.1, 0.1, 0.1));
}

TEST(ColorTest, Addition)
{
    EXPECT_EQ(Color(0.1, 0.2, 0.3) + Color(0.2, 0.1, 0.3), Color(0.3, 0.3, 0.6));
}

TEST(ColorTest, Subtraction)
{
    EXPECT_EQ(Color(0.1, 0.2, 0.3) - Color(0.2, 0.1, 0.3), Color(-0.1, 0.1, 0));
}

TEST(ColorTest, Multiplication)
{
    EXPECT_EQ(Color(0.1, 0.2, 0.3) * Color(0.2, 0.1, 0.3), Color(0.02, 0.02, 0.09));
}