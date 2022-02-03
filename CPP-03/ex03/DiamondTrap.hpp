/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 03-02-2022  by  `-'                        `-'                  */
/*   Updated: 03-02-2022 23:36 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap();
		DiamondTrap(DiamondTrap const &d);
		DiamondTrap(std::string const &name);
		~DiamondTrap();

		DiamondTrap	&operator=(DiamondTrap const &d);

		void	attack(std::string const &target);
		void	whoAmI(void);

		std::string	getName(void) const;
		int			getHealth(void) const;
		int			getEnergy(void) const;
		int			getDamage(void) const;

};

std::ostream	&operator<<(std::ostream &os, DiamondTrap const &d);

#endif