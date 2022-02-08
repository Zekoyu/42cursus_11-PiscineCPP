/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 03-02-2022  by  `-'                        `-'                  */
/*   Updated: 07-02-2022 14:11 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

DiamondTrap::DiamondTrap() { std::cout << "DiamondTrap default constructor called" << std::endl; }

DiamondTrap::DiamondTrap(DiamondTrap const &d) : _name(d.getName())
{
	(void)d;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap destructor called" << std::endl; }

DiamondTrap::DiamondTrap(std::string const &name)
{
	ClapTrap::setName(name + "_clap_name");
	this->_name = name;
	this->_hitPoints = FragTrap::getHealth();
	this->_energyPoints = ScavTrap::getEnergy();
	this->_attackDamage = FragTrap::getDamage();
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &d)
{
	this->_name = d.getName();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, DiamondTrap const &d)

{
	os << "DiamondTrap named " << d.getName() << " has " << d.getHealth() << " HP and " << d.getEnergy() << " energy.";
	return (os);
}

void	DiamondTrap::attack(std::string const &target) { ScavTrap::attack(target); }

void	DiamondTrap::whoAmI(void) { std::cout << "I am DiamondTrap " << this->_name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl; }

std::string	DiamondTrap::getName(void) const { return (this->_name); }

int			DiamondTrap::getHealth(void) const { return (this->_hitPoints); }

int			DiamondTrap::getEnergy(void) const { return (this->_energyPoints); }

int			DiamondTrap::getDamage(void) const { return (this->_attackDamage); }