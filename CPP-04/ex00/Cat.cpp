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

#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal("Cat") { std::cout << "Cat default constructor called" << std::endl; }

Cat::Cat(Cat const &d) : Animal(d.getType()) { std::cout << "Cat copy constructor called" << std::endl; }

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat	&Cat::operator=(Cat const &d)
{
	this->_type = d.getType();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Cat const &d)

{
	os << "I am a cat and my type is " << d.getType();
	return (os);
}

void	Cat::makeSound(void) const { std::cout << "Miew miew n**g**" << std::endl; }