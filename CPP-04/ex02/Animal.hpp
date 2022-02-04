/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 04-02-2022  by  `-'                        `-'                  */
/*   Updated: 04-02-2022 21:51 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	private:
		
	protected:
		std::string	_type;
	public:
		Animal();
		Animal(Animal const &a);
		Animal(std::string const &type);
		virtual ~Animal();

		Animal	&operator=(Animal const &a);

		// =0 make function pure virtual (abstract), = 0 means smth like "Non present", to avoid introducing new keyword
		virtual void		makeSound(void) const = 0;
		std::string			getType(void) const;
};

std::ostream	&operator<<(std::ostream &os, Animal const &a);

#endif