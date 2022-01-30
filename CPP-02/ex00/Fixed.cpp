/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 30-01-2022  by  `-'                        `-'                  */
/*   Updated: 30-01-2022 17:43 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : _value(0) { std::cout << "Fixed default constructor called" << std::endl; }

Fixed::Fixed(Fixed const &f) : _value(f.getRawBits())
{ std::cout << "Fixed copy constructor called" << std::endl; }

Fixed::~Fixed() { std::cout << "Fixed destructor called" << std::endl; }

Fixed	&Fixed::operator=(Fixed const &f)
{
	this->_value = f.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const 
{ 
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) { this->_value = raw; }
