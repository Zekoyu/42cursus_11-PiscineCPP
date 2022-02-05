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

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") { std::cout << "WrongCat default constructor called" << std::endl; }

WrongCat::WrongCat(WrongCat const &d) : WrongAnimal(d.getType()) { std::cout << "WrongCat copy constructor called" << std::endl; }

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

WrongCat	&WrongCat::operator=(WrongCat const &d)
{
	this->_type = d.getType();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, WrongCat const &d)

{
	std::cout << "I am a wrong cat and my type is " << d.getType();
	return (os);
}

void	WrongCat::makeSound(void) const { std::cout << "Miew miew n**g**" << std::endl; }