#include "../src/dog.h"

TEST(DogTest, DefaultConstructor)
{
    Dog d;
    ASSERT_EQ(d.name(), "");
    ASSERT_NEAR(d.weight(), 0, DELTA);
}

TEST(DogTest, Constructor1)
{
    std::string name = "Angle";
    double weight = 20.0;
    Dog d(name, weight);
    ASSERT_EQ(d.name(), name);
    ASSERT_NEAR(d.weight(), weight, DELTA);
}

TEST(DogTest, Constructor2)
{
    std::string name = "Olala";
    double weight = 5.0;
    ASSERT_THROW(Dog d(name, weight), std::range_error);
}

TEST(DogTest, Constructor3)
{
    std::string name = "Nelson";
    double weight = 80.0;
    ASSERT_THROW(Dog d(name, weight), std::range_error);
}

TEST(DogTest, Feed1)
{
    std::string name = "Canny";
    double weight = 40.0;
    Dog d(name, weight);
    d.feed();
    ASSERT_EQ(d.name(), name);
    ASSERT_NEAR(d.weight(), weight + 0.8, DELTA);
}

TEST(DogTest, Feed2)
{
    std::string name = "Din";
    double weight = 49.8;
    Dog d(name, weight);
    ASSERT_THROW(d.feed(), std::out_of_range);
}