/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 16:21 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		AMateria	*_inventory[4];
		std::string	_name;
	
		// Not const because getMateria will call use which is not const
		AMateria 			*getMateria(int const index) const;
		void				setMateria(int const index, AMateria *materia);
	public:
		Character();
		Character(Character const &c);
		Character(std::string const &name);
		~Character();

		Character	&operator=(Character const &c);

		

		// reference to const string, so that it also can't be modifed
		std::string const	&getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int index);
		void				use(int index, ICharacter &target);

};

std::ostream	&operator<<(std::ostream &os, Character const &c);

#endif