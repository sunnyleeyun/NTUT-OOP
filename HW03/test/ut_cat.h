#include "../src/cat.h"
#include <gtest/gtest.h>

const double DELTA = 0.001;

// add your test here

// getName
TEST(CatTest, GetName1) {
    std::string name = "Lucky";
    double weight = 15;
    Cat c(name, weight);
    std::string s = "Lucky";
    ASSERT_EQ(s, c.getName());
}
TEST(CatTest, GetName2) {
    std::string name = "Nike";
    double weight = 15;
    Cat c(name, weight);
    std::string s = "Nike";
    ASSERT_EQ(s, c.getName());
}

// getWeight
TEST(CatTest, GetWeight1) {
    std::string name = "Fluffy";
    double weight = 30.0;
    Cat c(name, weight);
    EXPECT_NEAR(30.0, c.getWeight(), DELTA);   
}
TEST(CatTest, GetWeight2) {
    std::string name = "Oreo";
    double weight = 18.5;
    Cat c(name, weight);
    EXPECT_NEAR(18.5, c.getWeight(), DELTA);   
}

// addNewToy
TEST(CatTest, AddNewToy1) {
    std::string name = "Pocky";
    double weight = 55;
    Cat c(name, weight);
    std::string t1 = "apple";
    std::string t2 = "banana";
    c.addNewToy(t1);
    c.addNewToy(t2);
    ASSERT_EQ(t1, c.getToy(0));
    ASSERT_EQ(t2, c.getToy(1));
    /*
    if (t) {
        delete [] t;
    }
    t = nullptr;
    */

}
TEST(CatTest, AddNewToy2) {
    std::string name = "Coco";
    double weight = 45;
    Cat c(name, weight);
    std::string t1 = "zebra";
    std::string t2 = "giraffe";
    std::string t3 = "elephant";
    c.addNewToy(t1);
    c.addNewToy(t2);
    c.addNewToy(t3);
    ASSERT_EQ(t1, c.getToy(0));
    ASSERT_EQ(t2, c.getToy(1));
    ASSERT_EQ(t3, c.getToy(2));
}

// getToy
TEST(CatTest, GetToy1) {
    std::string name = "cooper";
    double weight = 35;
    Cat c(name, weight);
    std::string t1 = "clock";
    c.addNewToy(t1);
    ASSERT_EQ(t1, c.getToy(0));
    ASSERT_THROW(c.getToy(1), std::string);
}
TEST(CatTest, GetToy2) {
    std::string name = "benz";
    double weight = 45;
    Cat c(name, weight);
    std::string t1 = "t-shirt";
    std::string t2 = "panty";
    std::string t3 = "short";
    std::string t4 = "glove";
    std::string t5 = "face mask";
    c.addNewToy(t1);
    c.addNewToy(t2);
    c.addNewToy(t3);
    c.addNewToy(t4);
    c.addNewToy(t5);
    ASSERT_EQ(t1, c.getToy(0));
    ASSERT_EQ(t2, c.getToy(1));
    ASSERT_EQ(t3, c.getToy(2));
    ASSERT_EQ(t4, c.getToy(3));
    ASSERT_EQ(t5, c.getToy(4));
}