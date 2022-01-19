#include "../src/dog.h"
#include "../src/pet.h"

#include <stdexcept>

const std::string dog = "DOG";

class DogTest : public ::testing::Test {
protected:
  void SetUp() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  void TearDown() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  const double DELTA = 0.001;
};


TEST_F(DogTest, AmountConstructor) {
  Dog dog("Dog", 30);
  ASSERT_EQ(1, Dog::amount());
}

TEST_F(DogTest, AmountCopyConstructor) {
  Dog dog_1("Dog", 30);
  Dog dog_2 = dog_1;
  ASSERT_EQ(2, Dog::amount());
}

TEST_F(DogTest, AmountPolymorphism) {
  Pet * pet = new Dog("Dog", 30);
  ASSERT_EQ(1, Pet::amount());
  ASSERT_EQ(1, Dog::amount());
  delete pet;
}

// Dog Test Unit: Without using Dog Test Class
TEST(DogTestUnit, DefaultConstructor)
{
    Dog d;
    ASSERT_EQ(d.kind(), dog);
    ASSERT_EQ(d.name(), "");
    ASSERT_NEAR(d.weight(), 0, DELTA);
}

TEST(DogTestUnit, Constructor1)
{
    std::string name = "Angle";
    double weight = 20.0;
    Dog d(name, weight);
    ASSERT_EQ(d.kind(), dog);
    ASSERT_EQ(d.name(), name);
    ASSERT_NEAR(d.weight(), weight, DELTA);
}

TEST(DogTestUnit, Constructor2)
{
    std::string name = "Olala";
    double weight = 5.0;
    ASSERT_THROW(Dog d(name, weight), std::range_error);
}

TEST(DogTestUnit, Constructor3)
{
    std::string name = "Nelson";
    double weight = 80.0;
    ASSERT_THROW(Dog d(name, weight), std::range_error);
}

TEST(DogTestUnit, Feed1)
{
    std::string name = "Canny";
    double weight = 40.0;
    Dog d(name, weight);
    d.feed();
    ASSERT_EQ(d.kind(), dog);
    ASSERT_EQ(d.name(), name);
    ASSERT_NEAR(d.weight(), weight + 0.8, DELTA);
}

TEST(DogTestUnit, Feed2)
{
    std::string name = "Din";
    double weight = 49.8;
    Dog d(name, weight);
    ASSERT_THROW(d.feed(), std::out_of_range);
}
