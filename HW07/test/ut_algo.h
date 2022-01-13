#include "../src/algo.h"
#include "../src/pet.h"
#include "../src/cat.h"
#include "../src/dog.h"

class AlgoTest : public ::testing::Test 
{
protected:
    std::vector<Pet *> pets;

    void SetUp() override
    {
        Pet* c1 = new Cat("Ku", 2.0);
        Pet* c2 = new Cat("Lee", 4.5);
        Pet* d1 = new Dog("Yang", 10);
        Pet* d2 = new Dog("Cheng", 45);
        Pet* d3 = new Dog("Lin", 50);
        pets = {c1, d3, c2, d1, d2};
    }

    void TearDown() override 
    {
        for (Pet* p : pets) delete p;
    }
};

bool cmpWeight(Pet *a, Pet *b)
{
    return a->weight() < b->weight();
}

TEST_F(AlgoTest, LargestWeight)
{
    Pet * largestWeight = *maxPet(pets.begin(), pets.end(), cmpWeight);
    ASSERT_NEAR(largestWeight->weight(), 50, DELTA);
}

bool cmpName(Pet *a, Pet *b)
{
    return a->name().length() < b->name().length();
}

TEST_F(AlgoTest, LongestName)
{
    Pet * longestName = *maxPet(pets.begin(), pets.end(), cmpName);
    ASSERT_EQ(longestName->name(), "Cheng");
}
