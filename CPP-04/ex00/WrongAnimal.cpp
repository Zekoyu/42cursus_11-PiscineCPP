/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 04-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 21:12 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() : _type("Unknown")
{ std::cout << "WrongAnimal default constructor called" << std::endl; }

WrongAnimal::WrongAnimal(WrongAnimal const &a) : _type(a.getType())
{ std::cout << "WrongAnimal copy constructor called" << std::endl; }

WrongAnimal::WrongAnimal(std::string const &type) : _type(type)
{ std::cout << "WrongAnimal string parameter constructor called" << std::endl; }

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &a)
{
	this->_type = a.getType();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, WrongAnimal const &a)

{
	os << "I am a wrong animal and my type is " << a.getType();
	return (os);
}

void		WrongAnimal::makeSound(void) const { std::cout << "* Weird sounds *" << std::endl; }

std::string	WrongAnimal::getType(void) const { return (this->_type); }