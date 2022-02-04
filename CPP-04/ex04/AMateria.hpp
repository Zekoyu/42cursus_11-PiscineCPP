/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 04-02-2022  by  `-'                        `-'                  */
/*   Updated: 04-02-2022 22:05 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

#include "ICharacter.hpp"

class AMateria
{
	private:
		
	protected:
		
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(AMateria const &a);
		~AMateria();

		AMateria	&operator=(AMateria const &a);

		// Returning const value can prevent from like "getType() = "pouet""
		std::string const	&getType;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter &target);

};

std::ostream	&operator<<(std::ostream &os, AMateria const &a);

#endif