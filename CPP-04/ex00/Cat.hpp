/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 04-02-2022  by  `-'                        `-'                  */
/*   Updated: 04-02-2022 19:04 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		
	public:
		Cat();
		Cat(Cat const &d);
		~Cat();

		Cat	&operator=(Cat const &d);
	
		void	makeSound(void) const;
};

std::ostream	&operator<<(std::ostream &os, Cat const &d);

#endif