#ifndef CAT_H
#define CAT_H
#include <string>

class Cat {
public:
  Cat() {}

  Cat(std::string name, double weight) {
    init(name, weight);
  }

  ~Cat() {
    if (this->_toyCollections) {
      delete [] this->_toyCollections;
    }
    this->_toyCollections = nullptr;
  }


  std::string getName() {
    return _name;
  }

  double getWeight() {
    return _weight;
  }

  void addNewToy(std::string toyName) {
    this->_toyAmount += 1;
    std::string * newToyCollection = new std::string[this->_toyAmount];
    for (int i = 0; i < this->_toyAmount - 1; i++) {
      newToyCollection[i] = this->_toyCollections[i];
    }
    newToyCollection[this->_toyAmount - 1] = toyName;
    if (this->_toyCollections) {
      delete [] this->_toyCollections;
    }

    this->_toyCollections = newToyCollection;

  }

  std::string getToy(int index) {
    if (index > this->_toyAmount - 1) {
      throw std::string("Index out of bounds.");
    }
    return this->_toyCollections[index];
  }

private:
  std::string _name;
  double _weight;
  std::string * _toyCollections;
  int _toyAmount;
  void init(std::string name, double weight) {
    this->_name = name;
    this->_weight = weight;
    this->_toyCollections = {};
    this->_toyAmount = 0;
  }
};

#endif