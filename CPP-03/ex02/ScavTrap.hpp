/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 01-02-2022  by  `-'                        `-'                  */
/*   Updated: 01-02-2022 22:08 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <iostream>

/*
	:	public <Class> 		public members remain public, protected member remain protected
	:	protected <Class> 	public members become protected, protected member remain protected	
	:	private <Class> 	public and protected members become private
*/
class ScavTrap : public ClapTrap
{
	private:
		ScavTrap();
	public:
		ScavTrap(std::string const &name);
		ScavTrap(ScavTrap const &s);
		~ScavTrap();

		ScavTrap	&operator=(ScavTrap const &s);

		void	attack(std::string const &target);
		void	guardGate(void) const;

};

std::ostream	&operator<<(std::ostream &os, ScavTrap const &s);

#endif