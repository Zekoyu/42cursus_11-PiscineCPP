/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 02-02-2022  by  `-'                        `-'                  */
/*   Updated: 07-02-2022 14:17 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	this->setHealth(100);
	this->setEnergy(100);
	this->setDamage(30);

	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	this->setHealth(100);
	this->setEnergy(100);
	this->setDamage(30);

	std::cout << "FragTrap string constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &s)
{
	this->setName(s.getName());
	this->setHealth(s.getHealth());
	this->setEnergy(s.getEnergy());
	this->setDamage(s.getDamage());

	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() { std::cout << "FragTrap destructor called" << std::endl; }

FragTrap	&FragTrap::operator=(FragTrap const &s)
{
	this->setName(s.getName());
	this->setHealth(s.getHealth());
	this->setEnergy(s.getEnergy());
	this->setDamage(s.getDamage());

	return (*this);
}

std::ostream	&operator<<(std::ostream &os, FragTrap const &s)

{
	os << "FragTrap named " << s.getName() << " has " << s.getHealth() << " HP and " << s.getEnergy() << " energy.";
	return (os);
}

void	FragTrap::attack(std::string const &target)
{
	
	if (this->_energyPoints >= 1)
	{
		std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getDamage() << " points of damage, he loses 1 energy." << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "FragTrap " << this->getName() << " does not have enough energy to attack." << std::endl;
}

void	FragTrap::highFivesGuys(void) const { std::cout << "FragTrap named " << this->getName() << " says \"Let's do this bois\"." << std::endl; }
