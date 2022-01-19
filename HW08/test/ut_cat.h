#include "../src/cat.h"
#include "../src/pet.h"

#include <stdexcept>

const double DELTA = 0.001;
const std::string cat = "CAT";

class CatTest : public ::testing::Test {
protected:
  void SetUp() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
  }

  void TearDown() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
  }

  const double DELTA = 0.001;
};


TEST_F(CatTest, AmountConstructor) {
  Cat cat("Cat", 3);
  ASSERT_EQ(1, Cat::amount());
}


TEST_F(CatTest, AmountCopyConstructor) {
  Cat cat_1("Cat", 3);
  Cat cat_2 = cat_1;
  ASSERT_EQ(2, Cat::amount());
}

TEST_F(CatTest, AmountPolymorphism) {
  Pet * pet = new Cat("Cat", 3);
  ASSERT_EQ(1, Pet::amount());
  ASSERT_EQ(1, Cat::amount());
  delete pet;
}

// Cat Test Unit: Without using Cat Test Class
TEST(CatTestUnit, DefaultConstructor)
{
    Cat c;
    ASSERT_EQ(c.kind(), cat);
    ASSERT_EQ(c.name(), "");
    ASSERT_NEAR(c.weight(), 0, DELTA);
}

TEST(CatTestUnit, Constructor1)
{
    std::string name = "Jenny";
    double weight = 2.0;
    Cat c(name, weight);
    ASSERT_EQ(c.kind(), cat);
    ASSERT_EQ(c.name(), name);
    ASSERT_NEAR(c.weight(), weight, DELTA);
}

TEST(CatTestUnit, Constructor2)
{
    std::string name = "Katie";
    double weight = 1.0;
    ASSERT_THROW(Cat c(name, weight), std::range_error);
}

TEST(CatTestUnit, Constructor3)
{
    std::string name = "Gigi";
    double weight = 7.0;
    ASSERT_THROW(Cat c(name, weight), std::range_error);
}

TEST(CatTestUnit, Feed1)
{
    std::string name = "Nemo";
    double weight = 5.0;
    Cat c(name, weight);
    c.feed();
    ASSERT_EQ(c.kind(), cat);
    ASSERT_EQ(c.name(), name);
    ASSERT_NEAR(c.weight(), weight + 0.2, DELTA);
}

TEST(CatTestUnit, Feed2)
{
    std::string name = "Zero";
    double weight = 6.0;
    Cat c(name, weight);
    ASSERT_THROW(c.feed(), std::out_of_range);
}
