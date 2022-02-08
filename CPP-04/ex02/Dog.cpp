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

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : AAnimal("Dog")
{
	this->_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &d) : AAnimal(d.getType())
{
	this->_brain = new Brain();
	this->_brain = d._brain; // Copy content
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog	&Dog::operator=(Dog const &d)
{
	Brain *tmp = new Brain(*(d._brain));
	this->_type = d.getType();
	delete this->_brain;
	this->_brain = tmp;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Dog const &d)

{
	os << "I am a dog and my type is " << d.getType() << std::endl;
	return (os);
}

void		Dog::makeSound(void) const { std::cout << "HHHEEOWWWW HHEEEOOWWW" << std::endl; }

void		Dog::setIdea(int const index, std::string const &idea) { this->_brain->setIdea(index, idea); }

std::string	Dog::getIdea(int const index) const { return (this->_brain->getIdea(index)); }