#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon) : _name(name), _weapon(weapon) { std::cout << "HumanA constructor called" << std::endl; }

HumanA::~HumanA() { std::cout << "HumanA (" << this->_name << ") destructor called" << std::endl; }

HumanA::HumanA(const HumanA &h) : _name(h.getName()), _weapon(h._weapon) { std::cout << "HumanA copy constructor called" << std::endl; }

HumanA	&HumanA::operator= (const HumanA &h)
{
	this->_name = h._name;
	this->_weapon = h._weapon;
	return (*this);
}

void		HumanA::attack(void) const { std::cout << this->getName() << " attacks with their " << this->_weapon.getType() << std::endl; }

std::string	HumanA::getName(void) const { return (this->_name); }

void		HumanA::setName(const std::string &name) { this->_name = name; }