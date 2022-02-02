/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 02-02-2022  by  `-'                        `-'                  */
/*   Updated: 02-02-2022 17:05 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>

class FragTrap : public ClapTrap
{
	private:
		FragTrap();
	public:
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &s);
		~FragTrap();

		FragTrap	&operator=(FragTrap const &s);

		void	attack(std::string const &target);
		void	highFivesGuys(void) const;

};

std::ostream	&operator<<(std::ostream &os, FragTrap const &s);

#endif