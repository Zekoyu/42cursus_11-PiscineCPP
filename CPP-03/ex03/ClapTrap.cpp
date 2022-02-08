/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 31-01-2022  by  `-'                        `-'                  */
/*   Updated: 07-02-2022 14:39 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{ std::cout << "ClapTrap default constructor called" << std::endl; }

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{ std::cout << "ClapTrap string parameter constructor called" << std::endl; }

ClapTrap::ClapTrap(ClapTrap const &c) : _name("ClapTrap"), _hitPoints(c._hitPoints), _energyPoints(c._energyPoints), _attackDamage(c._attackDamage)
{ std::cout << "ClapTrap copy constructor called" << std::endl; }

ClapTrap::~ClapTrap() { std::cout << "ClapTrap destructor called" << std::endl; }

ClapTrap	&ClapTrap::operator=(ClapTrap const &c)
{
	this->_name = c._name;
	this->_attackDamage = c._attackDamage;
	this->_energyPoints = c._energyPoints;
	this->_hitPoints = c._hitPoints;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, ClapTrap const &c)

{
	os << "ClapTrap named " << c.getName() << " has " << c.getHealth() << " HP and " << c.getEnergy() << " energy.";
	return (os);
}

void	ClapTrap::attack(std::string const &target)
{
	
	if (this->_energyPoints >= 1)
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getDamage() << " points of damage, he loses 1 energy." << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->getName() << " does not have enough energy to attack." << std::endl;
}

/*
	When an expression contains both signed and unsigned int values, the signed int will be automatically converted to unsigned int

	So we need to cast our unsigned int to signed int (basic int) to check if > 0

	UPDATE: We only check if health is negative, because if HP = 5 and damage 7, we should set health to -2 and not avoid
*/
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHealth() /*- (signed) amount*/ > 0)
	{
		std::cout << "ClapTrap " << this->getName() << " takes " << amount << " damage " << std::endl;
		this->_hitPoints -= amount;
	}
	else
		std::cout << "Stop ! ClapTrap " << this->getName() << " is already dead !" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints >= 1)
	{
		std::cout << "ClapTrap gained " << amount << " health, he now have " << this->getHealth() + amount << " HP and " << this->getEnergy() - 1 << " energy." << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->getName() << " does not have enough energy to repair itself." << std::endl;
	
}

std::string	ClapTrap::getName(void) const { return (this->_name); }

int			ClapTrap::getHealth(void) const { return (this->_hitPoints); }

int			ClapTrap::getEnergy(void) const { return (this->_energyPoints); }

int			ClapTrap::getDamage(void) const { return (this->_attackDamage); }

void		ClapTrap::setName(std::string const &name) { this->_name = name; }

void		ClapTrap::setEnergy(int const energy) { this->_energyPoints = energy; }

void		ClapTrap::setDamage(int const damage) { this->_attackDamage = damage; }

void		ClapTrap::setHealth(int const health) { this->_hitPoints = health; }

