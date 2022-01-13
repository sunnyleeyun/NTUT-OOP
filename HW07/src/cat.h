#ifndef CAT_H
#define CAT_H

#include "pet.h"

class Cat : public Pet
{
public:
    Cat()
    {
        this->_name = "";
        this->_weight = 0;
    }

    Cat(std::string name, double weight): _name(name), _weight(weight) 
    {
        if (weight < 2 || weight > 6) throw std::range_error("Weight out of range");    
    }

    ~Cat() override { }

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
        if ((this->_weight + 0.2) > 6) throw std::out_of_range("Out of range");
        this->_weight += 0.2;
    }

private:
    std::string _name;
    double _weight;
};
#endif