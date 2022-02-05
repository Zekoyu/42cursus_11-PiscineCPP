/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 21:12 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria() { std::cout << "AMateria default constructor called" << std::endl; }

AMateria::AMateria(AMateria const &a)
{
	(void) a;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{ std::cout << "AMateria string parameter called" << std::endl; }

AMateria::~AMateria() { std::cout << "AMateria destructor called" << std::endl; }

AMateria	&AMateria::operator=(AMateria const &a)
{
	this->_type = a.getType();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, AMateria const &a)
{
	os << "AMateria of type " << a.getType();
	return (os);
}

std::string const	&AMateria::getType(void) const { return (this->_type); }

void				AMateria::use(ICharacter &target) { std::cout << "Using abstract materia " << this->getType() << " on " << target.getName() << std::endl; }