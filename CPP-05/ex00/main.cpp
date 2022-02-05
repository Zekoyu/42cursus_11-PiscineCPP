/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 21:11 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
		{ Bureaucrat rondaz("Nab", 10); std::cout << rondaz << std::endl;} // should work
	catch(const std::exception& e)
		{ std::cerr << e.what() << std::endl; }

	try
		{ Bureaucrat walidou("Bg", 0); } // grade too high
	catch(const std::exception& e)
		{ std::cerr << e.what() << std::endl; }

	try
		{ Bureaucrat mea("Mea", 250); } // grade too low
	catch(const std::exception& e)
		{ std::cerr << e.what() << std::endl; }
	
}