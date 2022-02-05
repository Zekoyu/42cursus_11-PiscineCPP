/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 23:38 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Form f1("Simple form", 0, 50); // grade too high
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form f2("Simple form", 2, 151); // grade too low
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Form		*f3;
	Bureaucrat	pouet("Pouic", 2);
	Bureaucrat	pouic("Pouet", 69);

	try
	{
		f3 = new Form("Simple form", 2, 50); // correct
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *f3 << std::endl;

	try
	{
		pouic.signForm(*f3); // grade too low
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *f3 << std::endl;

	try
	{
		pouet.signForm(*f3); // correct
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *f3 << std::endl;

	delete f3;
}