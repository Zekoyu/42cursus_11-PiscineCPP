/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 06-02-2022 16:24 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Form	*fs = new ShrubberyCreationForm("Jungle");
	Form	*fr = new RobotomyRequestForm("Poutine");
	Form	*fp = new PresidentialPardonForm("Maitre gims");

	Bureaucrat	chad("Chad", 1);
	Bureaucrat	virgin("Virgin", 150);

	std::cout << *fs << std::endl;
	std::cout << *fr << std::endl;
	std::cout << *fp << std::endl;
	
	try
	{
		virgin.signForm(*fs); // should fail
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << *fs << std::endl; // form should not be signed

	try
	{
		fs->execute(chad); // should say not signed
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		chad.signForm(*fs); // should work
		chad.signForm(*fp); // should work
		chad.signForm(*fr); // should work
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << *fs << std::endl;
	std::cout << *fr << std::endl;
	std::cout << *fp << std::endl;

	chad.executeForm(*fs); // should work
	chad.executeForm(*fr); // should work
	virgin.executeForm(*fs); // should fail
	chad.executeForm(*fp); // should work

	delete fs;
	delete fr;
	delete fp;
}