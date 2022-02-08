/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 30-01-2022  by  `-'                        `-'                  */
/*   Updated: 04-02-2022 16:01 by                                             */
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

/*
	- Multiply the float value by 2^Fractional_bits (bitshift is easier for power):
		this gives us a integer value (with potential decimal part but it will get ignored)
	- 2.5 * (1 << 8) = 2.5 * 256 = 640, so our actual float value is 640.0
	- Then we round it (will change nothing in case of 2.5), this is where the precision loss occurs
	- Then the implicit cast from float to int will convert our 640.0 to 640 and store it in our _value
	(because 640.0 binary is not the number that we want)
	640 in binary is 1010000000, which in fixed point it 10.10000000 so we successfully converted to fixed point
	Because in fixed point, if we shift the decimal point, it will just multiply our number by 2, 2.5^8 = 640
*/
Fixed::Fixed(float const value) : _value(roundf(value * (1 << this->_fractionalBits)))
{ std::cout << "Fixed float parameter constructor called" << std::endl; }

Fixed::Fixed(Fixed const &f) : _value(f.getRawBits())
{ std::cout << "Fixed copy constructor called" << std::endl; }

Fixed::~Fixed() { std::cout << "Fixed destructor called" << std::endl; }

int		Fixed::getRawBits(void) const { return (this->_value); }

void	Fixed::setRawBits(int const raw) { this->_value = raw; }

float	Fixed::toFloat(void) const { return ((float) this->_value / (float) (1 << _fractionalBits)); }

int		Fixed::toInt(void) const { return (this->_value >> _fractionalBits); }

// Can't use ternary because is expects expressions, not statements (return is a statement)
// Need to return const because arg is const
Fixed const	&Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	if(lhs > rhs)
		return (lhs);
	return (rhs);
}

Fixed const	&Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	if(lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed 		&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if(lhs > rhs)
		return (lhs);
	return (rhs);
}

Fixed		 &Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if(lhs < rhs)
		return (lhs);
	return (rhs);
}

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

// Since our number is basically stored as a int and we just shift it to get the "real" value, we can perform comparisons on int directly
bool	Fixed::operator<(Fixed const &f) const { return (this->getRawBits() < f.getRawBits()); }

bool	Fixed::operator<=(Fixed const &f) const { return (this->getRawBits() <= f.getRawBits()); }

bool	Fixed::operator>(Fixed const &f) const { return (this->getRawBits() > f.getRawBits());; }

bool	Fixed::operator>=(Fixed const &f) const { return (this->getRawBits() >= f.getRawBits());; }

bool	Fixed::operator==(Fixed const &f) const { return (this->getRawBits() == f.getRawBits()); }

bool	Fixed::operator!=(Fixed const &f) const { return (this->getRawBits() != f.getRawBits()); }

//Temporary objects are destroyed as the last step in evaluating the full-expression (1.9) that (lexically) contains the point where they were created
// So temporary created here will not be immediately destroyed
// Cannot return a reference since res is allocated in stack
Fixed	Fixed::operator+(Fixed const &f) const 
{
	Fixed	res(this->toFloat() + f.toFloat());
	return (res);
}

Fixed	Fixed::operator-(Fixed const &f) const 
{
	Fixed	res(this->toFloat() - f.toFloat());
	return (res);
}

Fixed	Fixed::operator/(Fixed const &f) const
{
	Fixed	res(this->toFloat() / f.toFloat());
	return (res);
}

Fixed	Fixed::operator*(Fixed const &f) const
{
	Fixed	res(this->toFloat() * f.toFloat());
	return (res);
}

// prefix ++ return the new one
// Increment of the smallest value possible, so just increment the int and it will do it automatically

Fixed	Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return (Fixed(this->toFloat()));
}

// postfix ++ returns the old value
Fixed	Fixed::operator++(int)
{
	Fixed	save(this->toFloat());
	this->setRawBits(this->getRawBits() + 1);
	return (save);
}

Fixed	Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return (Fixed(this->toFloat()));
}

Fixed	Fixed::operator--(int)
{
	Fixed	save(this->toFloat());
	this->setRawBits(this->getRawBits() - 1);
	return (save);
}