/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 31-01-2022  by  `-'                        `-'                  */
/*   Updated: 31-01-2022 22:46 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;
		ClapTrap();
	public:
		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const &c);
		~ClapTrap();

		ClapTrap	&operator=(ClapTrap const &c);

		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int			getHealth(void) const;
		int			getEnergy(void) const;
		int			getDamage(void) const;
};

std::ostream	&operator<<(std::ostream &os, ClapTrap const &c);

#endif