#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>

#include "term.h"

class Polynomial {
public:
  Polynomial()
  {
    this->_degree = 0;

  }

  Polynomial(std::vector<Term> terms, int degree) 
  {
    std::vector<Term> tempVector;
    int index = 0, p = -1;
    std::stable_sort(terms.begin(), terms.end(), compare);
    for (std::vector<Term>::iterator it = terms.begin(); it != terms.end(); ++it)
    {
      if (p == it->exponent()) throw std::string("Repeat Terms");
      while (index < it->exponent())
      {
        tempVector.push_back(Term(0, index++));
      }
      
      tempVector.push_back(*it);
      p = index++;
    }
    
    this->_terms = tempVector;
    this->_degree = degree;
  }

  // get a term by exponent
  // If the term does not exist, return the term (0, exponent)
  Term term(int exponent) const 
  {
    if (this->_terms.size() <= exponent) return Term(0, exponent);
    return this->_terms.at(exponent);
  }

  // get the degree
  int degree() const 
  {
    return this->_degree;
  }

  // get the terms
  std::vector<Term> terms() const 
  {
    return this->_terms;
  }

  // add two polynomials
  Polynomial operator+ (const Polynomial & q) const 
  {
    std::vector<Term> tempVector;
    int index = 0, lastIndexCoefNotZero = 0;
    std::vector<Term> terms = this->_degree >= q.degree() ? this->_terms : q.terms();
    std::vector<Term> shortTerms = this->_degree >= q.degree() ? q.terms() : this->_terms;
    for (std::vector<Term>::iterator it = terms.begin(); it != terms.end(); ++it)
    {
      Term updatedTerm = *it + ((index <= shortTerms.size() - 1) ? shortTerms.at(index) : Term(0, index));
      tempVector.push_back(updatedTerm);
      if (updatedTerm.coefficient() != 0) lastIndexCoefNotZero = index;
      index++;
    }
    return Polynomial(tempVector, lastIndexCoefNotZero);
  }

  // multiply by a term
  Polynomial operator* (Term t) const 
  {
    std::vector<Term> tempVector;
    std::vector<Term> terms = this->_terms;
    int maxIndex = 0;
    for (std::vector<Term>::iterator it = terms.begin(); it != terms.end(); ++it)
    {
      Term updatedTerm = *it * t;
      tempVector.push_back(updatedTerm);
      if (updatedTerm.coefficient() != 0)
        maxIndex = updatedTerm.exponent() > maxIndex ? updatedTerm.exponent() : maxIndex;
    }
    return Polynomial(tempVector, maxIndex);
  }

  // multiply by another Polynomial
  Polynomial operator* (const Polynomial & q) const 
  {
    std::vector<Term> tempVector;
    for (int i = 0; i <= this->_degree + q.degree(); ++i)
      tempVector.push_back(Term(0, i));
    std::vector<Term> t1 = this->_terms;
    std::vector<Term> t2 = q.terms();
    int index = 0, maxIndex = 0;
    for (std::vector<Term>::iterator it1 = t1.begin(); it1 != t1.end(); ++it1)
    {
      for (std::vector<Term>::iterator it2 = t2.begin(); it2 != t2.end(); ++it2)
      {
        Term updatedTerm = *it1 * *it2;
        tempVector[updatedTerm.exponent()] = tempVector[updatedTerm.exponent()] + updatedTerm;
        if (updatedTerm.coefficient() != 0)
          maxIndex = updatedTerm.exponent() > maxIndex ? updatedTerm.exponent() : maxIndex;
      }
    }
    return Polynomial(tempVector, maxIndex);
  }

private:
  std::vector<Term> _terms;
  int _degree;

  static bool compare(Term i1, Term i2)
  {
    return (i1.exponent() < i2.exponent());
  }
};

#endif
