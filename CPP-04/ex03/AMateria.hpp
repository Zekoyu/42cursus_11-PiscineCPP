/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 04-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 16:22 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	private:
		
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(AMateria const &a);
		virtual ~AMateria(); // Virtual destructor since class is abstract, all childs have their own implementation

		AMateria	&operator=(AMateria const &a);

		// Returning const value can prevent from like `getType() = "pouet"`
		std::string const	&getType(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);

};

std::ostream	&operator<<(std::ostream &os, AMateria const &a);

#endif