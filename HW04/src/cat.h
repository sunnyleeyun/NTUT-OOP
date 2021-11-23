#ifndef CAT_H
#define CAT_H
#include "toy.h"
#include <vector>
#include <string>

class Cat 
{
public:
  // constructor
  Cat() 
  {
    this->_name = "";
    this->_weight = 0;
    this->_toyCollections = {};
    this->_toyAmount = 0;
  }

  Cat(std::string name, double weight) 
  {
    if (name.empty() || weight > 50 || weight < 10) 
      throw std::string("undefined");
    init(name, weight);
  }

  ~Cat() { }

  // copy constructor
  Cat(Cat const & other) 
  {
    this->_name = other._name;
    this->_weight = other._weight;
    this->_toyCollections = other._toyCollections;
    this->_toyAmount = other._toyAmount;
  }

  // copy assignment
  Cat & operator = (Cat const & other) 
  {
    this->_name = other._name;
    this->_weight = other._weight;
    this->_toyCollections = other._toyCollections;
    this->_toyAmount = other._toyAmount;
    return *this;
  }

  // get name
  std::string getName() const
  {
    return _name;
  }

  double getWeight() const
  {
    return _weight;
  }

  // add Toy in toy collections
  void addNewToy(Toy const & toyName) 
  {
    this->_toyCollections.push_back(toyName);
    this->_toyAmount = _toyCollections.size();
  }

  // index from 0
  Toy getToy(int index) const 
  {
    if (this->_toyAmount <= index || index < 0)
      throw std::string("undefined");
    return this->_toyCollections.at(index);
  }

  // true if heavier than (>) other
  bool isHeavierThan(Cat const & other) const 
  {
    return this->getWeight() > other.getWeight();
  }


private:
  std::string _name;
  double _weight;
  std::vector<Toy> _toyCollections;
  int _toyAmount;
  void init(std::string name, double weight) 
  {
    this->_name = name;
    this->_weight = weight;
    this->_toyCollections = {};
    this->_toyAmount = 0;
  }
};

#endif