#include <gtest/gtest.h>
#include <vector>

#include "../src/term.h"
#include "../src/polynomial.h"

const double DELTA = 0.001;

TEST(PolynomialTest, DefaultConstructor)
{
    Polynomial p;
    Term t;
    ASSERT_EQ(p.degree(), 0);
    ASSERT_EQ(p.term(0), t);
}

TEST(PolynomialTest, Constructor1)
{
    std::vector<Term> terms = { Term(-3, 0), Term(3, 0) };
    ASSERT_THROW(Polynomial p(terms, 0), std::string);
}


TEST(PolynomialTest, Constructor2)
{
    std::vector<Term> terms = {Term(-3, 2), Term(3, 0), Term(6, 3)};
    Polynomial p(terms, 3);
    ASSERT_EQ(p.term(0), Term(3, 0));
    ASSERT_EQ(p.term(1), Term(0, 1));
    ASSERT_EQ(p.term(2), Term(-3, 2));
    ASSERT_EQ(p.term(3), Term(6, 3));
    ASSERT_EQ(p.degree(), 3);
}

TEST(PolynomialTest, TermEmpty)
{
    std::vector<Term> terms = {Term(6, 3)};
    Polynomial p(terms, 3);
    ASSERT_EQ(p.term(0), Term(0, 0));
    ASSERT_EQ(p.term(1), Term(0, 1));
    ASSERT_EQ(p.term(2), Term(0, 2));
    ASSERT_EQ(p.term(3), Term(6, 3));
}

TEST(PolynomialTest, degree)
{
    std::vector<Term> terms = {Term(6, 3)};
    Polynomial p(terms, 3);
    ASSERT_EQ(p.degree(), 3);
}

TEST(PolynomialTest, OperatorPlus1)
{
    std::vector<Term> terms1 = {Term(-3, 2), Term(3, 0), Term(6, 3)};
    Polynomial p1(terms1, 3);
    
    std::vector<Term> terms2 = {Term(-2, 3)};
    Polynomial p2(terms2, 3);

    Polynomial p = p1 + p2;
    ASSERT_NEAR(3, p.term(0).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(1).coefficient(), DELTA);
    ASSERT_NEAR(-3, p.term(2).coefficient(), DELTA);
    ASSERT_NEAR(4, p.term(3).coefficient(), DELTA);
    ASSERT_EQ(p.degree(), 3);
}

TEST(PolynomialTest, OperatorPlus2)
{
    std::vector<Term> terms1 = {Term(-3, 2), Term(3, 0), Term(6, 3)};
    Polynomial p1(terms1, 3);
    
    std::vector<Term> terms2 = {Term(-2, 5)};
    Polynomial p2(terms2, 5);

    Polynomial p = p1 + p2;
    ASSERT_NEAR(3, p.term(0).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(1).coefficient(), DELTA);
    ASSERT_NEAR(-3, p.term(2).coefficient(), DELTA);
    ASSERT_NEAR(6, p.term(3).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(4).coefficient(), DELTA);
    ASSERT_NEAR(-2, p.term(5).coefficient(), DELTA);
    ASSERT_EQ(p.degree(), 5);
}

TEST(PolynomialTest, OperatorPlus3)
{
    std::vector<Term> terms1 = {Term(-3, 2), Term(3, 0), Term(6, 3)};
    Polynomial p1(terms1, 3);
    
    std::vector<Term> terms2 = {Term(-6, 3)};
    Polynomial p2(terms2, 3);

    Polynomial p = p1 + p2;
    ASSERT_NEAR(3, p.term(0).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(1).coefficient(), DELTA);
    ASSERT_NEAR(-3, p.term(2).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(3).coefficient(), DELTA);
    ASSERT_EQ(p.degree(), 2);
}

TEST(PolynomialTest, OperatorPlus4)
{
    std::vector<Term> terms1 = {Term(-3, 2), Term(3, 0), Term(6, 3)};
    Polynomial p1(terms1, 3);
    
    std::vector<Term> terms2 = {Term(3, 2), Term(-6, 3)};
    Polynomial p2(terms2, 3);

    Polynomial p = p1 + p2;
    ASSERT_NEAR(3, p.term(0).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(1).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(2).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(3).coefficient(), DELTA);
    ASSERT_EQ(p.degree(), 0);
}

TEST(PolynomialTest, OperatorPlus5)
{
    std::vector<Term> terms1 = {Term(-3, 2), Term(3, 0), Term(6, 3)};
    Polynomial p1(terms1, 3);
    
    std::vector<Term> terms2 = {Term(3, 2), Term(-3, 0),Term(-6, 3)};
    Polynomial p2(terms2, 3);

    Polynomial p = p1 + p2;
    ASSERT_NEAR(0, p.term(0).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(1).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(2).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(3).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(10).coefficient(), DELTA);
    ASSERT_EQ(p.degree(), 0);
}

TEST(PolynomialTest, OperatorMultipleTerm1)
{
    std::vector<Term> terms1 = {Term(-3, 2), Term(3, 0), Term(6, 3)};
    Polynomial p1(terms1, 3);
    
    Term t = {Term(1, 1)};
    
    Polynomial p = p1 * t;
    ASSERT_NEAR(0, p.term(0).coefficient(), DELTA);
    ASSERT_NEAR(3, p.term(1).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(2).coefficient(), DELTA);
    ASSERT_NEAR(-3, p.term(3).coefficient(), DELTA);
    ASSERT_NEAR(6, p.term(4).coefficient(), DELTA);
    ASSERT_EQ(p.degree(), 4);
}

TEST(PolynomialTest, OperatorMultipleTerm2)
{
    std::vector<Term> terms1 = {Term(-3, 2), Term(3, 0), Term(6, 3)};
    Polynomial p1(terms1, 3);
    
    Term t = {Term(2, 2)};
    
    Polynomial p = p1 * t;
    ASSERT_NEAR(0, p.term(0).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(1).coefficient(), DELTA);
    ASSERT_NEAR(6, p.term(2).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(3).coefficient(), DELTA);
    ASSERT_NEAR(-6, p.term(4).coefficient(), DELTA);
    ASSERT_NEAR(12, p.term(5).coefficient(), DELTA);
    ASSERT_EQ(p.degree(), 5);
}

TEST(PolynomialTest, OperatorMultipleTerm3)
{
    std::vector<Term> terms1 = {Term(-3, 2), Term(3, 0), Term(6, 3)};
    Polynomial p1(terms1, 3);
    
    Term t = {Term(0, 2)};
    
    Polynomial p = p1 * t;
    ASSERT_NEAR(0, p.term(0).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(1).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(2).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(3).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(4).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(5).coefficient(), DELTA);
    ASSERT_EQ(p.degree(), 0);
}

TEST(PolynomialTest, OperatorMultiplePol)
{
    std::vector<Term> terms1 = {Term(-3, 2), Term(3, 0), Term(6, 3)};
    Polynomial p1(terms1, 3);
    
    std::vector<Term> terms2 = {Term(2, 0), Term(2, 2)};
    Polynomial p2(terms2, 2);
    
    Polynomial p = p1 * p2;
    ASSERT_NEAR(6, p.term(0).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(1).coefficient(), DELTA);
    ASSERT_NEAR(0, p.term(2).coefficient(), DELTA);
    ASSERT_NEAR(12, p.term(3).coefficient(), DELTA);
    ASSERT_NEAR(-6, p.term(4).coefficient(), DELTA);
    ASSERT_NEAR(12, p.term(5).coefficient(), DELTA);
    ASSERT_EQ(p.degree(), 5);
}