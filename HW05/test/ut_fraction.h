#include "../src/fraction.h"
#include <gtest/gtest.h>

// add your test here
TEST(FractionTest, DefaultConstructor)
{
    Fraction f;
    ASSERT_EQ(f.numerator(), 0);
    ASSERT_EQ(f.denominator(), 1);
    ASSERT_EQ(f.sign(), '+');
}

TEST(FractionTest, OneParameterConstructor1)
{
    Fraction f(-3);
    ASSERT_EQ(f.numerator(), 3);
    ASSERT_EQ(f.denominator(), 1);
    ASSERT_EQ(f.sign(), '-');
}

TEST(FractionTest, OneParameterConstructor2)
{
    Fraction f(3);
    ASSERT_EQ(f.numerator(), 3);
    ASSERT_EQ(f.denominator(), 1);
    ASSERT_EQ(f.sign(), '+');
}

TEST(FractionTest, TwoParameterConstructorException)
{
    ASSERT_THROW(Fraction f(3, 0), std::string);
}

TEST(FractionTest, TwoParameterConstructor1)
{
    Fraction f(0, 30);
    ASSERT_EQ(f.numerator(), 0);
    ASSERT_EQ(f.denominator(), 1);
    ASSERT_EQ(f.sign(), '+');
}

TEST(FractionTest, TwoParameterConstructor2)
{
    Fraction f(2, 7);
    ASSERT_EQ(f.numerator(), 2);
    ASSERT_EQ(f.denominator(), 7);
    ASSERT_EQ(f.sign(), '+');
}

TEST(FractionTest, TwoParameterConstructor3)
{
    Fraction f(-2, 7);
    ASSERT_EQ(f.numerator(), 2);
    ASSERT_EQ(f.denominator(), 7);
    ASSERT_EQ(f.sign(), '-');
}

TEST(FractionTest, TwoParameterConstructor4)
{
    Fraction f(2, -7);
    ASSERT_EQ(f.numerator(), 2);
    ASSERT_EQ(f.denominator(), 7);
    ASSERT_EQ(f.sign(), '-');
}

TEST(FractionTest, TwoParameterConstructor5)
{
    Fraction f(-2, -7);
    ASSERT_EQ(f.numerator(), 2);
    ASSERT_EQ(f.denominator(), 7);
    ASSERT_EQ(f.sign(), '+');
}

TEST(FractionTest, TwoParameterConstructor6)
{
    Fraction f(20, 15);
    ASSERT_EQ(f.numerator(), 4);
    ASSERT_EQ(f.denominator(), 3);
    ASSERT_EQ(f.sign(), '+');
}

TEST(FractionTest, TwoParameterConstructor7)
{
    Fraction f(20, -180);
    ASSERT_EQ(f.numerator(), 1);
    ASSERT_EQ(f.denominator(), 9);
    ASSERT_EQ(f.sign(), '-');
}

TEST(FractionTest, ToString1)
{
    Fraction f(3, 2);
    ASSERT_EQ(f.toString(), std::string("3/2"));
}

TEST(FractionTest, ToString2)
{
    Fraction f(-3, 1);
    ASSERT_EQ(f.toString(), std::string("-3"));
}

TEST(FractionTest, ToString3)
{
    Fraction f(-30, 15);
    ASSERT_EQ(f.toString(), std::string("-2"));
}

TEST(FractionTest, ToString4)
{
    Fraction f(-3, 41);
    ASSERT_EQ(f.toString(), std::string("-3/41"));
}

TEST(FractionTest, ToString5)
{
    Fraction f(-20, -50);
    ASSERT_EQ(f.toString(), std::string("2/5"));
}

TEST(FractionTest, OperatorAdd1)
{
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction res = f1 + f2;
    ASSERT_EQ(res.toString(), std::string("5/6"));
}

TEST(FractionTest, OperatorAdd2)
{
    Fraction f1(1, -2);
    Fraction f2(1, 3);
    Fraction res = f1 + f2;
    ASSERT_EQ(res.toString(), std::string("-1/6"));
}

TEST(FractionTest, OperatorAdd3)
{
    Fraction f1(1, -2);
    Fraction f2(1, -3);
    Fraction res = f1 + f2;
    ASSERT_EQ(res.toString(), std::string("-5/6"));
}

TEST(FractionTest, OperatorAdd4)
{
    Fraction f1(50, 100);
    Fraction f2(1, -3);
    Fraction res = f1 + f2;
    ASSERT_EQ(res.toString(), std::string("1/6"));
}

TEST(FractionTest, OperatorMinus1)
{
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction res = f1 - f2;
    ASSERT_EQ(res.toString(), std::string("1/6"));
}

TEST(FractionTest, OperatorMinus2)
{
    Fraction f1(25, 50);
    Fraction f2(1, 3);
    Fraction res = f1 - f2;
    ASSERT_EQ(res.toString(), std::string("1/6"));
}

TEST(FractionTest, OperatorMinus3)
{
    Fraction f1(1, 2);
    Fraction f2(-1, 3);
    Fraction res = f1 - f2;
    ASSERT_EQ(res.toString(), std::string("5/6"));
}

TEST(FractionTest, OperatorDivide1)
{
    Fraction f1(1, 2);
    Fraction f2(1, 3);
    Fraction res = f1 / f2;
    ASSERT_EQ(res.toString(), std::string("3/2"));
}

TEST(FractionTest, OperatorDivide2)
{
    Fraction f1(2, 4);
    Fraction f2(1, 3);
    Fraction res = f1 / f2;
    ASSERT_EQ(res.toString(), std::string("3/2"));
}
TEST(FractionTest, OperatorDivide3)
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction res = f1 / f2;
    ASSERT_EQ(res.toString(), std::string("1"));
}

TEST(FractionTest, OperatorDivide4)
{
    Fraction f1(1, 2);
    Fraction f2(-1, 3);
    Fraction res = f1 / f2;
    ASSERT_EQ(res.toString(), std::string("-3/2"));
}


TEST(FractionTest, FractionNumerator)
{
    Fraction f(-3, 7);
    ASSERT_EQ(f.numerator(), 3);
}

TEST(FractionTest, FractionDenominator)
{
    Fraction f(-3, 7);
    ASSERT_EQ(f.denominator(), 7);
}

TEST(FractionTest, FractionSign)
{
    Fraction f(-3, 7);
    ASSERT_EQ(f.sign(), '-');
}