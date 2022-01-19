#ifndef CAT_H
#define CAT_H

#include <stdexcept>
#include <string>

#include "pet.h"


class Cat : public Pet 
{
public:

  /*  add and modify your code from assignment 8  */
  Cat(): Pet("CAT", "", 0) 
  {
    ++_amount; 
  }

  Cat(std::string name, double weight): Pet("CAT", name, weight)
  {
    if (weight < 2 || weight > 6) throw std::range_error("Weight out of range");
    ++_amount;
  }

  Cat(Cat const & c): Pet("CAT", c.name(), c.weight())
  {
    ++_amount;
  }

  ~Cat() override 
  { 
    --_amount;
  }

  void feed() override
  {
    double _weight = weight();
    if ((_weight + 0.2) > 6) throw std::out_of_range("Out of range");
    _weight += 0.2;
    updateWeight(_weight);
  }

  static int amount() 
  {
    return _amount;
  }

private:
  static int _amount;

};

int Cat::_amount = 0;


#endif /* end of include guard: CAT_H */
