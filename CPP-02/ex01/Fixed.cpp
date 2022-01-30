/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 30-01-2022  by  `-'                        `-'                  */
/*   Updated: 30-01-2022 23:32 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <math.h>

Fixed::Fixed() : _value(0) 
{ std::cout << "Fixed default constructor called" << std::endl; }

#include <bitset>


Fixed::Fixed(int const value) : _value(value << this->_fractionalBits) // Shift the int to be in the left (integer) part
{ std::cout << "Fixed int parameter constructor called" << std::endl; }

Fixed::Fixed(float const value) : _value(roundf(value * (1 << this->_fractionalBits))) // floating_input * 2^(fractional_bits) Round x to the nearest whole number
{ std::cout << "Fixed float parameter constructor called" << std::endl; }

Fixed::Fixed(Fixed const &f) : _value(f.getRawBits())
{ std::cout << "Fixed copy constructor called" << std::endl; }

Fixed::~Fixed() { std::cout << "Fixed destructor called" << std::endl; }

int		Fixed::getRawBits(void) const 
{ 
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) { this->_value = raw; }

float	Fixed::toFloat(void) const { return ((float) this->_value / (float) (1 << _fractionalBits)); }

int		Fixed::toInt(void) const { return (this->_value >> _fractionalBits); }

Fixed	&Fixed::operator=(Fixed const &f)
{
	this->_value = f.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Fixed const &f)
{
	os << f.toFloat();
	return (os);
}
