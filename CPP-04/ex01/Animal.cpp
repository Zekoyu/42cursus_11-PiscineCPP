/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 04-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 00:15 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>

Animal::Animal() : _type("Unknown")
{ std::cout << "Animal default constructor called" << std::endl; }

Animal::Animal(Animal const &a) : _type(a.getType())
{ std::cout << "Animal copy constructor called" << std::endl; }

Animal::Animal(std::string const &type) : _type(type)
{ std::cout << "Animal string parameter constructor called" << std::endl; }

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal	&Animal::operator=(Animal const &a)
{
	//this->_type = a.getType();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Animal const &a)

{
	std::cout << "I am an animal and my type is " << a.getType() << std::endl;
	return (os);
}

/*
	No virtual = bound at compile time (use class type => Animal => will call Animal::makeSound)
	virtual = bound at runtime: check Class and call it's function
*/
void		Animal::makeSound(void) const { std::cout << "* Weird sounds *" << std::endl; }

std::string	Animal::getType(void) const { return (this->_type); }