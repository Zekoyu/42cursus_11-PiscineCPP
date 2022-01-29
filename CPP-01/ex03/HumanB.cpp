#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name)
{
	std::cout << "HumanB constructor called" << std::endl;
	this->_weapon = NULL;
	this->_name = name;
}

HumanB::HumanB() { this->_name = ""; this->_weapon = NULL; }

HumanB::~HumanB() { std::cout << "HumanB (" << this->_name << ") destructor called" << std::endl; }

HumanB::HumanB(const HumanB &h)
{
	std::cout << "HumanB copy constructor called" << std::endl;
	this->_name = h._name;
	this->_weapon = h._weapon;
}

HumanB	&HumanB::operator= (const HumanB &h)
{
	this->_name = h._name;
	this->_weapon = h._weapon;
	return (*this);
}

void	HumanB::attack(void) const 
{ 
	if (this->_weapon)
		std::cout << this->getName() << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->getName() << " has no weapon ..." << std::endl;
}

void	HumanB::setWeapon(Weapon &w) { this->_weapon = &w; }

std::string	HumanB::getName(void) const { return (this->_name); }

void		HumanB::setName(const std::string &name) { this->_name = name; }

