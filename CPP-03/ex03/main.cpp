/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 31-01-2022  by  `-'                        `-'                  */
/*   Updated: 03-02-2022 23:38 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "DiamondTrap.hpp"


int main()
{
	
	DiamondTrap	gigaNoob("Oronda");

	std::cout << gigaNoob<< std::endl;
	gigaNoob.attack("Pouic");
	gigaNoob.takeDamage(5);
	std::cout << gigaNoob<< std::endl;
	gigaNoob.beRepaired(4);
	std::cout << gigaNoob<< std::endl;
	gigaNoob.whoAmI();
	gigaNoob.guardGate();
	gigaNoob.highFivesGuys();

}