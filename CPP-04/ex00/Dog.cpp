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

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal("Dog") { std::cout << "Dog default constructor called" << std::endl; }

Dog::Dog(Dog const &d) : Animal(d.getType()) 
{ std::cout << "Dog copy constructor called" << std::endl; }

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog	&Dog::operator=(Dog const &d)
{
	this->_type = d.getType();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Dog const &d)

{
	os << "I am a dog and my type is " << d.getType();
	return (os);
}

void	Dog::makeSound(void) const { std::cout << "HHHEEOWWWW HHEEEOOWWW" << std::endl; }