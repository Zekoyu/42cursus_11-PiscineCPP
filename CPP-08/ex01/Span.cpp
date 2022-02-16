/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 16-02-2022  by  `-'                        `-'                  */
/*   Updated: 16-02-2022 16:57 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <iostream>
#include <cmath>

Span::Span() : _values(new int[0]),  _valuesCount(0), _capacity(0)
{ std::cout << "Span default constructor called" << std::endl; }

Span::Span(Span const &s) : _values(s._values), _valuesCount(s._valuesCount), _capacity(s._capacity)
{ std::cout << "Span copy constructor called" << std::endl; }

Span::Span(int const size) : _values(new int[size]), _valuesCount(0), _capacity(size)
{ std::cout << "Span int parameter constructor called" << std::endl; }

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
	delete[] this->_values;
}

Span	&Span::operator=(Span const &s)
{
	this->_values = s._values;
	this->_valuesCount = s._valuesCount;
	this->_capacity = s._capacity;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Span const &s)
{
	(void) s;
	os << "Span";
	return (os);
}

char const	*Span::SpanAlreadyFullException::what(void) const throw() { return ("Span is full, cannot add a number"); }

char const	*Span::TooFewNumbersException::what(void) const throw() { return ("There are less than 2 numbers in the Span"); }

void	Span::addNumber(int const n)
{
	if (this->_valuesCount >= this->_capacity)
		throw (SpanAlreadyFullException());
	this->_values[this->_valuesCount] = n;
	this->_valuesCount++;
}

int		Span::shortestSpan(void) const
{
	int	shortest = INT_MAX;
	int	tmp;

	if (this->_valuesCount < 2)
		throw (TooFewNumbersException());
	for (int i = 0; i < this->_valuesCount - 1; i++)
	{
		tmp = std::abs(this->_values[i] - this->_values[i + 1]);
		if (tmp < shortest)
			shortest = tmp;
	}
	return (shortest);
}

int		Span::longestSpan(void) const
{
	int	longest = 0;
	int	tmp;

	if (this->_valuesCount < 2)
		throw (TooFewNumbersException());
	for (int i = 0; i < this->_valuesCount - 1; i++)
	{
		tmp = std::abs(this->_values[i] - this->_values[i + 1]);
		if (tmp > longest)
			longest = tmp;
	}
	return (longest);
}