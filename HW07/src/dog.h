#ifndef DOG_H
#define DOG_H

#include "pet.h"

class Dog : public Pet
{
public:
    Dog()
    {
        this->_name = "";
        this->_weight = 0;
    }

    Dog(std::string name, double weight): _name(name), _weight(weight) 
    {
        if (weight < 10 || weight > 50) throw std::range_error("Weight out of range");    
    }

    ~Dog() override { }

    std::string name() const override
    {
        return this->_name;
    }

    double weight() const override
    {
        return this->_weight;
    }

    void feed() override
    {
        if ((this->_weight + 0.8) > 50) throw std::out_of_range("Out of range");
        this->_weight += 0.8;
    }

private:
    std::string _name;
    double _weight;
};
#endif