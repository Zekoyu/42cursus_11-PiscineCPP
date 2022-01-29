#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon() { this->setType("Bare hands"); }

Weapon::Weapon(const std::string &type)
{
	std::cout << "Weapon constructor called" << std::endl;
	this->setType(type);
}

Weapon::~Weapon() { std::cout << "Weapon (" << this->getType() << ") destructor called" << std::endl; }

Weapon::Weapon(const Weapon &w) { this->setType(w.getType()); }

Weapon &Weapon::operator=(const Weapon &w)
{
	this->setType(w.getType());
	return (*this);
}

std::string	Weapon::getType(void) const { return (this->_type); }

void		Weapon::setType(const std::string &type) { this->_type = type; }
