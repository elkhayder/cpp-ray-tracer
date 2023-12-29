#include <gtest/gtest.h>

#include "../src/math/matrix.h"

TEST(MatrixTest, Equality)
{
    Matrix m(4);

    m.Set(0, 0, 1);
    m.Set(0, 1, 2);
    m.Set(0, 2, 3);
    m.Set(0, 3, 4);
    m.Set(1, 0, 1);
    m.Set(1, 1, 2);
    m.Set(1, 2, 3);
    m.Set(1, 3, 4);
    m.Set(2, 0, 1);
    m.Set(2, 1, 2);
    m.Set(2, 2, 3);
    m.Set(2, 3, 4);
    m.Set(3, 0, 1);
    m.Set(3, 1, 2);
    m.Set(3, 2, 3);
    m.Set(3, 3, 4);

    EXPECT_EQ(m, m);
}