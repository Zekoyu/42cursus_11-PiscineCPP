/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 30-01-2022  by  `-'                        `-'                  */
/*   Updated: 31-01-2022 16:18 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

#include <iostream>

int main(void) {
	
	Point a(0, 0);
	Point b(28.25, 0.5);
	Point c(-0.75, 30);

	Point p1(5.5, 2);
	Point p2(-1.0, 5.25);

	std::cout << "A: " << a << ", B: " << b << ", C: " << c << std::endl;
	
	if (bsp(a, b, c, p1))
		std::cout << "Point " << p1 << " is in triangle ABC" << std::endl;
	else
		std::cout << "Point " << p1 << " is not in triangle ABC" << std::endl;

	if (bsp(a, b, c, p2))
		std::cout << "Point " << p2 << " is in triangle ABC" << std::endl;
	else
		std::cout << "Point " << p2 << " is not in triangle ABC" << std::endl;
}