/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 09-02-2022  by  `-'                        `-'                  */
/*   Updated: 09-02-2022 15:02 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

#include <iostream>
#include <stdlib.h>

Data::Data() : someData(std::rand() % 100), someOtherData(42)
{ std::cout << "Data default constructor called" << std::endl; }

Data::Data(Data const &d) : someData(d.someData), someOtherData(d.someOtherData)
{ std::cout << "Data copy constructor called" << std::endl; }

Data::~Data() { std::cout << "Data destructor called" << std::endl; }

Data	&Data::operator=(Data const &d)
{
	(void) d;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Data const &d)

{
	std::cout << "Some data: " << d.someData << ", some other data: " << d.someOtherData;
	return (os);
}