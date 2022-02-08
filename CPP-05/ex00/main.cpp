/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 08-02-2022 14:03 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	/*
		Catch by reference for derived class of 'to catch' type
		https://stackoverflow.com/questions/2522299/c-catch-blocks-catch-exception-by-value-or-reference

		If you expect an exception and throw a GradeTooHighException, it will be converted to an exception, and print
		the message of Exception instead of GradeTooHighException
	*/
	try
	{
		Bureaucrat rondaz("Nab", 10); // should work
		std::cout << rondaz << std::endl;
	} 
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat walidou("Bg", 0); // grade too high
	} 
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat mea("Mea", 250);// grade too low
	} 
	catch(const std::exception& e)
		{ std::cerr << e.what() << std::endl;
	}
	
}