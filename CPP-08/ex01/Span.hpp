/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 15-02-2022  by  `-'                        `-'                  */
/*   Updated: 15-02-2022 15:58 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>

class Span
{
	private:
		int	_values[];
		int	_valuesCount;
	public:
		Span();
		Span(Span const &s);
		~Span();

		Span	&operator=(Span const &s);

		/* Public members */

};

std::ostream	&operator<<(std::ostream &os, Span const &s);

#endif