#ifndef DOG_H
#define DOG_H

#include <stdexcept>
#include <string>

#include "pet.h"


class Dog : public Pet 
{
public:

  /*  add and modify your code from assignment 8  */
  Dog() : Pet("DOG", "", 0) 
  {
    ++_amount;
  }

  Dog(std::string name, double weight): Pet("DOG", name, weight)
  {
    if (weight < 10 || weight > 50) throw std::range_error("Weight out of range");    
    ++_amount;
  }

  Dog(Dog const & d): Pet("DOG", d.name(), d.weight())
  {
    ++_amount;
  }

  ~Dog() override 
  { 
    --_amount;
  }

  void feed() override
  {
    double _weight = weight();
    if ((_weight + 0.8) > 50) throw std::out_of_range("Out of range");
    _weight += 0.8;
    updateWeight(_weight);
  }

  static int amount() 
  {
    return _amount;
  }

private:
  static int _amount;

};

int Dog::_amount = 0;


#endif /* end of include guard: DOG_H */
