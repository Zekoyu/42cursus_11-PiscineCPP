#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() { this->_name = "Zombie"; }

Zombie::Zombie(const std::string name) : _name(name) { std::cout << "Zombie constructor called" << std::endl; }

Zombie::Zombie(const Zombie& z) 
{ 
	std::cout << "Zombie copy constructor called" << std::endl;
	this->_name = z._name;
}

Zombie::~Zombie() { std::cout << "Zombie " << this->getName() << " destructor called" << std::endl;; }

Zombie& Zombie::operator= (const Zombie& z) 
{
	this->setName(z.getName());
	return (*this);
}

void Zombie::setName(std::string str) { this->_name = str; }
std::string Zombie::getName(void) const { return (this->_name); }

void Zombie::announce(void) const { std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl; }
