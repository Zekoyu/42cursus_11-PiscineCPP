/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 09-02-2022  by  `-'                        `-'                  */
/*   Updated: 09-02-2022 14:59 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data
{
	private:
		
	public:
		int const	someData;
		int const	someOtherData;

		Data();
		Data(Data const &d);
		~Data();

		Data	&operator=(Data const &d);

};

std::ostream	&operator<<(std::ostream &os, Data const &d);

#endif