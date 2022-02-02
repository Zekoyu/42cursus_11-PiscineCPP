/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 31-01-2022  by  `-'                        `-'                  */
/*   Updated: 02-02-2022 17:07 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

int main()
{
	ClapTrap	nab("Oronaze");
	ScavTrap	chad("Mea");
	FragTrap	pouet("Pouic");

	std::cout << nab << std::endl;
	nab.attack("Walid");
	nab.takeDamage(3); // Ouch
	std::cout << nab << std::endl;

	chad.attack("Pouic");
	std::cout << chad << std::endl;

	chad.guardGate();
	chad.takeDamage(25);
	std::cout << chad << std::endl;

	chad.takeDamage(75);
	std::cout << chad << std::endl; 

	chad.takeDamage(1); // Should print "stop, claptrap Mea is already dead" since takeDamage is not overloaded

	std::cout << pouet << std::endl;

	pouet.attack("someone");
	pouet.takeDamage(5);
	std::cout << pouet << std::endl;

	pouet.highFivesGuys();
}