/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 31-01-2022  by  `-'                        `-'                  */
/*   Updated: 31-01-2022 16:14 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

#include <iostream>

class Point
{
	private:
		Fixed const _x; // We cannot initialize it because the value might be variable, const just means it will be initialized once, we could initialize it if it was static
		Fixed const _y;
	public:
		Point();
		Point(Point const &p);
		Point(float const &x, float const &y);
		~Point();

		Point	&operator=(Point const &p);

		Fixed	getX(void) const;
		Fixed	getY(void) const;

		int		getiX(void) const; // return X as int
		int		getiY(void) const;

		float	getfX(void) const; // return X as float
		float	getfY(void) const;
};

std::ostream	&operator<<(std::ostream &os, Point const &p);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif