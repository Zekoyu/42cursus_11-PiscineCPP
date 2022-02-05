/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 16:24 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#include <iostream>

Ice::Ice() : AMateria("ice") { std::cout << "Ice default constructor called" << std::endl; }

Ice::Ice(Ice const &i) : AMateria("ice")
{
	std::cout << "Ice copy constructor called" << std::endl;
	(void) i;
}

Ice::~Ice() { std::cout << "Ice destructor called" << std::endl; }

Ice	&Ice::operator=(Ice const &i)
{
	(void) i;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Ice const &i)

{
	std::cout << "Ice materia of type " << i.getType() << std::endl;
	return (os);
}

void	Ice::use(ICharacter &target) { std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;}

Ice		*Ice::clone(void) const { return (new Ice(*this)); } // creates a clone of itself with copy constructor
