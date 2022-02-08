/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 04-02-2022  by  `-'                        `-'                  */
/*   Updated: 07-02-2022 14:56 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	private:
		
	protected:
		std::string	_type;
	public:
		AAnimal();
		AAnimal(AAnimal const &a);
		AAnimal(std::string const &type);
		virtual ~AAnimal();

		AAnimal	&operator=(AAnimal const &a);

		// =0 make function pure virtual (abstract), = 0 means smth like "Non present", to avoid introducing new keyword
		virtual void		makeSound(void) const = 0;
		std::string			getType(void) const;
};

std::ostream	&operator<<(std::ostream &os, AAnimal const &a);

#endif