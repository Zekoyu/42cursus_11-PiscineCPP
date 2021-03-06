/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 15-02-2022  by  `-'                        `-'                  */
/*   Updated: 16-02-2022 13:44 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <list>

#include <iostream>

int main()
{
	std::vector<int> values2(5, 42);

	try
	{
		easyfind(values2, 42);
		std::cout << "Found value 42" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "An error occured: " << e.what() << std::endl;
	}

	try
	{
		easyfind(values2, 41);
		std::cout << "Found value 41" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "An error occured: " << e.what() << std::endl;
	}

	std::list<int> values(5, 42);

	try
	{
		easyfind(values, 42);
		std::cout << "Found value 42" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "An error occured: " << e.what() << std::endl;
	}

	try
	{
		easyfind(values, 41);
		std::cout << "Found value 41" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "An error occured: " << e.what() << std::endl;
	}
}