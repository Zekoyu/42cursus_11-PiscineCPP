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

#include "Cat.hpp"

#include <iostream>

Cat::Cat() : AAnimal("Cat")
{
	this->_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &d) : AAnimal(d.getType())
{
	this->_brain = new Brain();
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() 
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat	&Cat::operator=(Cat const &d)
{
	Brain *tmp = new Brain(*(d._brain));
	this->_type = d.getType();
	this->_brain = tmp;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Cat const &d)

{
	os << "I am a cat and my type is " << d.getType() << std::endl;
	return (os);
}

void	Cat::makeSound(void) const { std::cout << "Miew miew n**g**" << std::endl; }