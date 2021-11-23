#include "../src/cat.h"
#include "../src/toy.h"
#include <gtest/gtest.h>

// add your test here
// getName
TEST(CatTest, GetName) {
    std::string name = "Tommy";
    double weight = 15;
    Cat c(name, weight);
    std::string s = "Tommy";
    ASSERT_EQ(s, c.getName());
}

// throw exception if Cat have no name
TEST(CatTest, NoName) {
    double weight = 15;
    ASSERT_THROW(Cat c("", weight), std::string);
}

// throw exception if weight of Cat is out of range
TEST(CatTest, TooFat) {
    std::string name = "Will";
    double weight = 70;
    ASSERT_THROW(Cat c(name, weight), std::string);
}

// copy constructor
TEST(CatTest, CopyConstructor) {
    std::string name = "Happy";
    double weight = 50;
    Cat c2(name, weight);
    Cat c1(c2);
    std::string s = "Happy";
    double w = 50;
    ASSERT_EQ(s, c2.getName());
    ASSERT_EQ(w, c2.getWeight());
}

// copy assignment
TEST(CatTest, CopyAssignment) {
    std::string name = "Candy";
    double weight = 10;
    Cat c2(name, weight);
    Cat c1(c2);
    std::string s = "Candy";
    double w = 10;
    ASSERT_EQ(s, c2.getName());
    ASSERT_EQ(w, c2.getWeight());
}

// addNewToy
TEST(CatTest, AddNewToy) {
    std::string name = "Jeans";
    double weight = 40;
    Cat c(name, weight);
    std::string t = "toilet";
    Toy toy = Toy(t);
    c.addNewToy(toy);
    ASSERT_EQ(t, c.getToy(0).getName());
}

// getToy: sequential
TEST(CatTest, GetToy1) {
    std::string name = "Magnet";
    double weight = 30;
    Cat c(name, weight);
    std::string t1 = "helmet";
    std::string t2 = "bat";
    Toy toy1 = Toy(t1);
    Toy toy2 = Toy(t2);
    c.addNewToy(toy1);
    c.addNewToy(toy2);
    ASSERT_EQ(t1, c.getToy(0).getName());
    ASSERT_EQ(t2, c.getToy(1).getName());
}

// getToy: throw
TEST(CatTest, GetToy2) {
    std::string name = "Zara";
    double weight = 30;
    Cat c(name, weight);
    std::string t1 = "Skirt";
    std::string t2 = "Necklace";
    Toy toy1 = Toy(t1);
    Toy toy2 = Toy(t2);
    c.addNewToy(toy1);
    c.addNewToy(toy2);
    ASSERT_EQ(t1, c.getToy(0).getName());
    ASSERT_EQ(t2, c.getToy(1).getName());
    ASSERT_THROW(c.getToy(2), std::string);
    ASSERT_THROW(c.getToy(-1), std::string);
}

// isHeavierThan
TEST(CatTest, IsHeavierThan) {
    std::string name1 = "Christina";
    double weight1 = 50;
    Cat c1(name1, weight1);
    std::string name2 = "Meridith";
    double weight2 = 45;
    Cat c2(name2, weight2);
    ASSERT_EQ(c1.isHeavierThan(c2), true);
}