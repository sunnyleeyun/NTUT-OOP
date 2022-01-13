#ifndef PET_H
#define PET_H

class Pet
{
public:
    Pet() {
        this->_name = "";
        this->_weight = 0;
    }
    Pet(std::string name, double weight): _name(name), _weight(weight) { }

    virtual ~Pet() { }
    virtual std::string name() const
    {
        return this->_name;
    }

    virtual double weight() const
    {
        return this->_weight;
    }
    
    virtual void feed() = 0;

private:
    std::string _name;
    double _weight;
};

#endif