/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 31-01-2022  by  `-'                        `-'                  */
/*   Updated: 31-01-2022 22:54 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iostream>

int main()
{
	ClapTrap	nab("Oronaze");

	nab.attack("Walid");
	std::cout << nab << std::endl;

	nab.takeDamage(3); // Ouch
	std::cout << nab << std::endl;

	nab.takeDamage(20); // Finish him
	std::cout << nab << std::endl;

	nab.takeDamage(10); // Don't kill him though
	std::cout << nab << std::endl;

	nab.beRepaired(2);
	nab.beRepaired(2);
	nab.beRepaired(2);
	nab.beRepaired(2);
	nab.beRepaired(2);
	nab.beRepaired(2);
	nab.beRepaired(2);
	nab.beRepaired(2);
	nab.beRepaired(2);
	nab.beRepaired(2); // Not enough energy
	nab.beRepaired(2);
}