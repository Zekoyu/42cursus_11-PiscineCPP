/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 04-02-2022  by  `-'                        `-'                  */
/*   Updated: 04-02-2022 19:08 by                                             */
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
		~Animal();

		Animal	&operator=(Animal const &a);

		virtual void		makeSound(void) const;
		std::string			getType(void) const;
};

std::ostream	&operator<<(std::ostream &os, Animal const &a);

#endif