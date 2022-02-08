/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 01-02-2022  by  `-'                        `-'                  */
/*   Updated: 07-02-2022 14:17 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	this->setHealth(100);
	this->setEnergy(50);
	this->setDamage(20);

	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	this->setHealth(100);
	this->setEnergy(50);
	this->setDamage(20);

	std::cout << "ScavTrap string constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &s)
{
	this->setName(s.getName());
	this->setHealth(s.getHealth());
	this->setEnergy(s.getEnergy());
	this->setDamage(s.getDamage());

	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap destructor called" << std::endl; }

ScavTrap	&ScavTrap::operator=(ScavTrap const &s)
{
	this->setName(s.getName());
	this->setHealth(s.getHealth());
	this->setEnergy(s.getEnergy());
	this->setDamage(s.getDamage());

	return (*this);
}

std::ostream	&operator<<(std::ostream &os, ScavTrap const &s)

{
	os << "ScavTrap named " << s.getName() << " has " << s.getHealth() << " HP and " << s.getEnergy() << " energy.";
	return (os);
}

void	ScavTrap::attack(std::string const &target)
{
	
	if (this->_energyPoints >= 1)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getDamage() << " points of damage, he loses 1 energy." << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ScavTrap " << this->getName() << " does not have enough energy to attack." << std::endl;
}

void	ScavTrap::guardGate(void) const { std::cout << "ScavTrap named " << this->getName() << " is now in gate keeper mode." << std::endl; }
