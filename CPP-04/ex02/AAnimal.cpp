/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 04-02-2022  by  `-'                        `-'                  */
/*   Updated: 07-02-2022 14:57 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

#include <iostream>

AAnimal::AAnimal() : _type("Unknown")
{ std::cout << "AAnimal default constructor called" << std::endl; }

AAnimal::AAnimal(AAnimal const &a) : _type(a.getType())
{ std::cout << "AAnimal copy constructor called" << std::endl; }

AAnimal::AAnimal(std::string const &type) : _type(type)
{ std::cout << "AAnimal string parameter constructor called" << std::endl; }

AAnimal::~AAnimal() { std::cout << "AAnimal destructor called" << std::endl; }

AAnimal	&AAnimal::operator=(AAnimal const &a)
{
	this->_type = a.getType();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, AAnimal const &a)

{
	os << "I am an animal and my type is " << a.getType();
	return (os);
}

std::string	AAnimal::getType(void) const { return (this->_type); }