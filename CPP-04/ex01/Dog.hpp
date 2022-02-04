/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 04-02-2022  by  `-'                        `-'                  */
/*   Updated: 04-02-2022 19:48 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog();
		Dog(Dog const &d);
		~Dog();

		Dog	&operator=(Dog const &d);
	
		void		makeSound(void) const;
		void		setIdea(int const index, std::string const &idea);
		std::string	getIdea(int const index) const;
};

std::ostream	&operator<<(std::ostream &os, Dog const &d);

#endif