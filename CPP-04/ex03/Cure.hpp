/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 00:26 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>

#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		
	public:
		Cure();
		Cure(Cure const &i);
		~Cure();

		Cure	&operator=(Cure const &i);

		void	use(ICharacter &target);
		Cure		*clone(void) const;
};

std::ostream	&operator<<(std::ostream &os, Cure const &i);

#endif