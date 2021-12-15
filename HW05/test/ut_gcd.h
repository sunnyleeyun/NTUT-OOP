// #include "../src/fraction.h"
#include "../src/gcd.h"
#include <gtest/gtest.h>


TEST(GcdTest, GcdBasic1)
{
    ASSERT_EQ(5, gcd(20, 15));
}

TEST(GcdTest, GcdBasic2)
{
    ASSERT_EQ(15, gcd(105, 30));
}

TEST(GcdTest, GcdBasic3)
{
    ASSERT_EQ(5, gcd(-20, 15));
}

TEST(GcdTest, GcdBasic4)
{
    ASSERT_EQ(15, gcd(105, -30));
}

TEST(GcdTest, GcdBasic5)
{
    ASSERT_EQ(50, gcd(50, 100));
}

TEST(GcdTest, GcdBasic6)
{
    ASSERT_EQ(50, gcd(-50, -100));
}
