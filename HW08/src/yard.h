#ifndef YARD_H
#define YARD_H

#include <vector>

#include "pet.h"


class Yard 
{
public:
  Yard() = default;

  Yard(Yard const & y)
  {
    initPets(y._pets);
  }

  Yard operator=(const Yard & y) 
  {
    if (this != &y)
    {
      clearPets();
      initPets(y._pets);      
    }
    return *this;
  }

  ~Yard() 
  {
    clearPets();
  }

  template<typename Condition>
  std::vector<Pet *> getPetWithCondition(Condition cond) 
  {
    std::vector<Pet *> pets_in_cond;
    for (Pet * pet : _pets) {
      if (cond(pet)) {
        pets_in_cond.push_back(pet);
      }
    }
    return pets_in_cond;
  }

  void addPet(Pet * pet) 
  {
    _pets.push_back(pet);
  }

  std::vector<Pet *> pets() const
  {
    return _pets;
  }


private:
  std::vector<Pet *> _pets;
  void clearPets() { for (Pet* p : _pets) delete p; }
  void initPets(std::vector<Pet *> y_pets)
  {
    for (Pet* p : y_pets)
    {
      if (p->kind() == "CAT") 
      {
        Pet* c = new Cat(p->name(), p->weight());
        addPet(c);
      } 
      else if (p->kind() == "DOG")
      {
        Pet* d = new Dog(p->name(), p->weight());
        addPet(d);
      }
      else 
      {
        throw std::string("Type Error");
      }
    }
  }
};


#endif /* end of include guard: YARD_H */
