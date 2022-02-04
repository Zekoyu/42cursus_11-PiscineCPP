/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 04-02-2022  by  `-'                        `-'                  */
/*   Updated: 04-02-2022 19:47 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain() { std::cout << "Brain default constructor called" << std::endl; }

Brain::Brain(Brain const &b)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = b._ideas[i];
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

Brain	&Brain::operator=(Brain const &b)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = b._ideas[i];
	return (*this);
}

void		Brain::setIdea(int const index, std::string const &idea)
{
	if (index >= 0 && index <= 99)
		this->_ideas[index] = idea;
}

std::string	Brain::getIdea(int const index) const
{
	if (index >= 0 && index <= 99)
		return (this->_ideas[index]);
	return ("");
}
