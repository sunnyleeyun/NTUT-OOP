#ifndef TOY_H
#define TOY_H
#include <string>

class Toy {
public:
  // default constructor
  Toy() { }

  // constructor with parameter
  Toy(std::string name) 
  {
    init(name);
  }

  // get the name of the toy
  std::string getName() const 
  {
    return _name;
  }

private:
  // add data member
  std::string _name;
  void init(std::string name)  
  {
    this->_name = name;
  }
};

#endif