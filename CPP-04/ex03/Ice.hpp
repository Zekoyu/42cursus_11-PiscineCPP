/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 00:20 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include <iostream>

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		
	public:
		Ice();
		Ice(Ice const &i);
		~Ice();

		Ice	&operator=(Ice const &i);

		void	use(ICharacter &target);
		Ice		*clone(void) const;
};

std::ostream	&operator<<(std::ostream &os, Ice const &i);

#endif