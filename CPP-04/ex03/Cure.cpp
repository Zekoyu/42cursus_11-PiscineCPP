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

#include "Cure.hpp"

#include <iostream>

Cure::Cure() : AMateria("cure") { std::cout << "Cure default constructor called" << std::endl; }

Cure::Cure(Cure const &i) : AMateria("cure")
{
	std::cout << "Cure copy constructor called" << std::endl;
	(void) i;
}

Cure::~Cure() { std::cout << "Cure destructor called" << std::endl; }

Cure	&Cure::operator=(Cure const &i)
{
	(void) i;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Cure const &i)

{
	std::cout << "Cure materia of type " << i.getType() << std::endl;
	return (os);
}

void	Cure::use(ICharacter &target) { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;}

Cure		*Cure::clone(void) const { return (new Cure(*this)); } // creates a clone of itself with copy constructor
