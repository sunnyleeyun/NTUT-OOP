#include "../src/cat.h"

const double DELTA = 0.001;

TEST(CatTest, DefaultConstructor)
{
    Cat c;
    ASSERT_EQ(c.name(), "");
    ASSERT_NEAR(c.weight(), 0, DELTA);
}

TEST(CatTest, Constructor1)
{
    std::string name = "Jenny";
    double weight = 2.0;
    Cat c(name, weight);
    ASSERT_EQ(c.name(), name);
    ASSERT_NEAR(c.weight(), weight, DELTA);
}

TEST(CatTest, Constructor2)
{
    std::string name = "Katie";
    double weight = 1.0;
    ASSERT_THROW(Cat c(name, weight), std::range_error);
}

TEST(CatTest, Constructor3)
{
    std::string name = "Gigi";
    double weight = 7.0;
    ASSERT_THROW(Cat c(name, weight), std::range_error);
}

TEST(CatTest, Feed1)
{
    std::string name = "Nemo";
    double weight = 5.0;
    Cat c(name, weight);
    c.feed();
    ASSERT_EQ(c.name(), name);
    ASSERT_NEAR(c.weight(), weight + 0.2, DELTA);
}

TEST(CatTest, Feed2)
{
    std::string name = "Zero";
    double weight = 6.0;
    Cat c(name, weight);
    ASSERT_THROW(c.feed(), std::out_of_range);
}

