/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 16:20 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#include <iostream>

Character::Character() : _name("Someone")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->setMateria(i, NULL);
}

Character::Character(Character const &c) : _name(c.getName())
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		// Here no need to check if there was a previous materia since it's constructor
		if (c._inventory[i])
			this->setMateria(i, c._inventory[i]->clone());
		else
			this->setMateria(i, NULL);
	}
}

Character::Character(std::string const &name) : _name(name)
{
	std::cout << "Character string parameter constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->setMateria(i, NULL);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
}

Character	&Character::operator=(Character const &c)
{
	this->_name = c.getName();
	for (int i = 0; i < 4; i++)
	{
		if (c._inventory[i])
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = c._inventory[i]->clone();
		}
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Character const &c)

{
	std::cout << "Character " << c.getName() << std::endl;
	return (os);
}

AMateria 			*Character::getMateria(int const index) const
{
	if (index >= 0 && index < 4) { return (this->_inventory[index]); }
	return (NULL);
}

void				Character::setMateria(int const index, AMateria *materia) { if (index >= 0 && index < 4) { this->_inventory[index] = materia;} }

std::string const	&Character::getName(void) const { return (this->_name); }

void				Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->getMateria(i) == NULL)
		{
			this->setMateria(i, m);
			break;
		}
	}
}

void				Character::unequip(int index)
{
	if (this->getMateria(index))
		this->setMateria(index, NULL);
}

void				Character::use(int index, ICharacter &target)
{
	if (this->getMateria(index))
		this->getMateria(index)->use(target);
}