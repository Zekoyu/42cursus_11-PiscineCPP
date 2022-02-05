/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 04-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 16:17 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>

#include "AMateria.hpp"

class AMateria;
/*
	Interface: only pure virtual functions
	No need for constructor etc.
*/
class ICharacter
{
	public:
		virtual	~ICharacter() {} // Provides default destructor
		virtual std::string const	&getName(void) const = 0;

		// Here we have circular includes: AMateria includes ICharacter, which includes AMateria, but with the header guard, it isn't included again
		// so the compiler has no idea about AMateria at this stage
		virtual void				equip(AMateria *m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter &target) = 0;

};


#endif