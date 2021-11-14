#include "HumanB.hpp"


HumanB::HumanB(std::string name)
:
    _name(name),
    _weapon(new Weapon())
{

}

HumanB::HumanB(const HumanB& copy)
:
    _name(copy._name),
    _weapon(copy._weapon)
{}

HumanB::~HumanB() 
{}

HumanB &HumanB::operator=(const HumanB& op)
{
    if (this == &op)
        return (*this);
    this->_name = op._name;
    this->_weapon = op._weapon;
    return (*this);
}

void HumanB::attack()
{
    std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
