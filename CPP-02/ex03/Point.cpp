/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 31-01-2022  by  `-'                        `-'                  */
/*   Updated: 31-01-2022 16:12 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <iostream>

Point::Point() : _x(0), _y(0) { std::cout << "Point default constructor called" << std::endl; }

Point::Point(Point const &p) : _x(p._x), _y(p._y)
{ std::cout << "Point copy constructor called" << std::endl; }

Point::Point(float const &x, float const &y) : _x(x), _y(y)
{ std::cout << "Point 2 float parameters constructor called" << std::endl; }

Point::~Point() { std::cout << "Point destructor called" << std::endl; }

Fixed	Point::getX(void) const { return (this->_x); }

Fixed	Point::getY(void) const { return (this->_y); }

int		Point::getiX(void) const { return (this->_x).toInt(); }

int		Point::getiY(void) const { return (this->_y).toInt(); }

float	Point::getfX(void) const { return (this->_x).toFloat(); }

float	Point::getfY(void) const { return (this->_y).toFloat(); }

Point	&Point::operator=(Point const &p)
{
	// Drop the const qualifier internally, but value is still const for user, this shouldn't be done but we have no choice
	(Fixed&) (this->_x) = p._x;
	(Fixed&) (this->_y) = p._y;
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Point const &p)
{
	os << "(" << p.getfX() << "; " << p.getfY() << ")";
	return (os);
}