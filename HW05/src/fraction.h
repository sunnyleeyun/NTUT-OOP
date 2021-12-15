#ifndef Fraction_H
#define Fraction_H
#include <string>
#include "./gcd.h"

class Fraction 
{
public:

  // default value is +0/1
  // i.e., _sign='+', _numerator=0, _denominator=1
  Fraction() 
  {
    dummyInit();
  }

  // default value is an integer (denominator=1)
  // e.g., Fraction f(-3) has its _sign='-', _numerator=3, _denominator=1
  Fraction(int num) 
  {
    if (num == 0)
      dummyInit();
    else
    {
      this->_sign = num < 0 ? '-' : '+';
      this->_numerator = num < 0 ? -num : num;
      this->_denominator = 1;
    }
  }

  // hint: use gcd
  // throw exception when the denominator is 0
  Fraction(int numerator, int denominator) 
  {
    if (denominator == 0)
      throw std::string("The denominator cannot be zero.");
    
    if (numerator == 0)
    {
      dummyInit();
      return;
    }
     
    if ((numerator > 0 && denominator > 0) || (numerator < 0 && denominator < 0))
      this->_sign = '+';
    else
      this->_sign = '-';
    int gcdValue = gcd(numerator, denominator);
    this->_numerator = numerator < 0 ? -numerator / gcdValue : numerator / gcdValue;
    this->_denominator = denominator < 0 ? -denominator / gcdValue : denominator / gcdValue;
  }

  // get the numerator of the fraction
  int numerator() const 
  {
    return this->_numerator;
  }

  // get the denominator of the fraction
  int denominator() const 
  {
    return this->_denominator;
  }

  // get positive or negative sign of the fraction
  char sign() const 
  {
    return this->_sign;
  }

  // display the fraction by string
  std::string toString() const 
  {
    std::string val = "";
    if (this->_denominator == 1)
      val = std::to_string(this->_numerator);
    else 
      val = std::to_string(this->_numerator) + "/" + std::to_string(this->_denominator);
    return (this->_sign == '-' ? "-" : "") + val;
  }

  // addition of two Fractions
  Fraction operator + (Fraction const & f) const 
  {
    int gcdValue = gcd(this->_denominator, f.denominator());
    int d = this->_denominator * f.denominator() / gcdValue;
    int n1 = this->_numerator * d / this->_denominator;
    int n2 = f.numerator() * d / f.denominator();
    if (this->_sign == '-')
      n1 = -n1;
    if (f.sign() == '-')
      n2 = -n2;
    int n = n1 + n2;
    return Fraction(n, d);
  }

  // subtraction of two Fractions
  Fraction operator - (Fraction const & f) const
  {
    int gcdValue = gcd(this->_denominator, f.denominator());
    int d = this->_denominator * f.denominator() / gcdValue;
    int n1 = this->_numerator * d / this->_denominator;
    int n2 = f.numerator() * d / f.denominator();
    if (this->_sign == '-')
      n1 = -n1;
    if (f.sign() == '+')
      n2 = -n2;
    int n = n1 + n2;
    return Fraction(n, d);
  }

  // division of two Fractions
  Fraction operator / (Fraction const & f) const 
  {
    int n = this->_numerator * f.denominator();
    int d = this->_denominator * f.numerator();
    if ((this->_sign == '-' && f.sign() == '+') || (this->_sign == '+' && f.sign() == '-'))
      n = -n;
    return Fraction(n, d);
  }

private:
  // both numerator and denominator should be positive
  int _numerator;
  int _denominator;
  char _sign;

  void dummyInit() 
  {
    this->_sign = '+';
    this->_numerator = 0;
    this->_denominator = 1;
  }
};

#endif