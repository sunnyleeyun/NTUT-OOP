#include "../src/cat.h"
#include "../src/dog.h"
#include "../src/pet.h"
#include "../src/yard.h"

#include <gtest/gtest.h>
#include <vector>


class YardTest : public ::testing::Test {
protected:
  void SetUp() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  void TearDown() override {
    ASSERT_EQ(0, Pet::amount());
    ASSERT_EQ(0, Cat::amount());
    ASSERT_EQ(0, Dog::amount());
  }

  const double DELTA = 0.001;
};

std::vector<Pet *> MakePets() {
  std::vector<Pet *> pets;
  Pet* c1 = new Cat("Kristen", 4.5);
  Pet* c2 = new Cat("Sarah", 3);
  Pet* d1 = new Dog("Ja", 45);
  Pet* d2 = new Dog("Clive", 30);
  pets = {c1, c2, d1, d2};
  return pets;
}

TEST_F(YardTest, Lambda) {
  Yard y;
  std::vector<Pet *> pets = MakePets();
  for (Pet* p : pets) {
    y.addPet(p);
  }
  std::vector<Pet *> pc = y.getPetWithCondition(
    [](Pet* p) 
    { 
      return (p->kind() == dog && p->weight() >= 45) || (p->kind() == cat && p->weight() >= 4.5); 
    }
  );
  ASSERT_EQ(pc.size(), 2);
  ASSERT_EQ(pc[0]->name(), "Kristen");
  ASSERT_EQ(pc[0]->kind(), cat);
  ASSERT_NEAR(pc[0]->weight(), 4.5, DELTA);
  ASSERT_EQ(pc[1]->name(), "Ja");
  ASSERT_EQ(pc[1]->kind(), dog);
  ASSERT_NEAR(pc[1]->weight(), 45, DELTA);
}


bool cmp(Pet *p)
{
  return (p->kind() == dog && p->weight() >= 45) || (p->kind() == cat && p->weight() >= 4.5);
}

TEST_F(YardTest, Function) {
  Yard y;
  std::vector<Pet *> pets = MakePets();
  for (Pet* p : pets) {
    y.addPet(p);
  }
  std::vector<Pet *> pc = y.getPetWithCondition(cmp);
  ASSERT_EQ(pc.size(), 2);
  ASSERT_EQ(pc[0]->name(), "Kristen");
  ASSERT_EQ(pc[0]->kind(), cat);
  ASSERT_NEAR(pc[0]->weight(), 4.5, DELTA);
  ASSERT_EQ(pc[1]->name(), "Ja");
  ASSERT_EQ(pc[1]->kind(), dog);
  ASSERT_NEAR(pc[1]->weight(), 45, DELTA);
}

class CmpPuffyPet {
public:
  CmpPuffyPet() {}
  bool operator()(Pet *p)
  {
    return (p->kind() == dog && p->weight() >= 45) || (p->kind() == cat && p->weight() >= 4.5);
  }
};

TEST_F(YardTest, Functor) {
  Yard y;
  std::vector<Pet *> pets = MakePets();
  for (Pet* p : pets) {
    y.addPet(p);
  }
  CmpPuffyPet cmpFunctor;
  std::vector<Pet *> pc = y.getPetWithCondition(cmpFunctor);
  ASSERT_EQ(pc.size(), 2);
  ASSERT_EQ(pc[0]->name(), "Kristen");
  ASSERT_EQ(pc[0]->kind(), cat);
  ASSERT_NEAR(pc[0]->weight(), 4.5, DELTA);
  ASSERT_EQ(pc[1]->name(), "Ja");
  ASSERT_EQ(pc[1]->kind(), dog);
  ASSERT_NEAR(pc[1]->weight(), 45, DELTA);
}


TEST_F(YardTest, CopyConstructor) {
  Yard y1;
  std::vector<Pet *> pets = MakePets();
  for (Pet* p : pets) {
    y1.addPet(p);
  }
  Yard y2 = y1;
  ASSERT_EQ(y2.pets().size(), 4);
  ASSERT_EQ(y2.pets()[0]->name(), "Kristen");
  ASSERT_NEAR(y2.pets()[0]->weight(), 4.5, DELTA);
  ASSERT_EQ(y2.pets()[1]->name(), "Sarah");
  ASSERT_NEAR(y2.pets()[1]->weight(), 3, DELTA);
  ASSERT_EQ(y2.pets()[2]->name(), "Ja");
  ASSERT_NEAR(y2.pets()[2]->weight(), 45, DELTA);
  ASSERT_EQ(y2.pets()[3]->name(), "Clive");
  ASSERT_NEAR(y2.pets()[3]->weight(), 30, DELTA);
}

TEST_F(YardTest, CopyAssignment) {
  Yard y1, y2;
  std::vector<Pet *> pets = MakePets();
  for (Pet* p : pets) {
    y1.addPet(p);
  }
  y2 = y1;
  ASSERT_EQ(y2.pets().size(), 4);
  ASSERT_EQ(y2.pets()[0]->name(), "Kristen");
  ASSERT_NEAR(y2.pets()[0]->weight(), 4.5, DELTA);
  ASSERT_EQ(y2.pets()[1]->name(), "Sarah");
  ASSERT_NEAR(y2.pets()[1]->weight(), 3, DELTA);
  ASSERT_EQ(y2.pets()[2]->name(), "Ja");
  ASSERT_NEAR(y2.pets()[2]->weight(), 45, DELTA);
  ASSERT_EQ(y2.pets()[3]->name(), "Clive");
  ASSERT_NEAR(y2.pets()[3]->weight(), 30, DELTA);
}

TEST_F(YardTest, Destructor) {
  Yard *y = new Yard();
  std::vector<Pet *> pets = MakePets();
  for (Pet* p : pets) {
    y->addPet(p);
  }
  delete y;
  ASSERT_EQ(0, Pet::amount());
  ASSERT_EQ(0, Cat::amount());
  ASSERT_EQ(0, Dog::amount());
}