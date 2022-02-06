/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 06-02-2022 18:14 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern		i;
	Form		*f = NULL;
	Bureaucrat	boss("Boss", 1);
	
	f = i.makeForm("robotomy_request", "Some random human"); // valid
	if (f)
	{
		boss.signForm(*f);
		boss.executeForm(*f);
		delete f;
	}
	else
		std::cerr << "Form not found" << std::endl;

	f = i.makeForm("some_random_form", "Some random target"); // invalid
	if (f)
	{
		boss.signForm(*f);
		boss.executeForm(*f);
		delete f;
	}
	else
		std::cerr << "Form not found" << std::endl;

	f = i.makeForm("presidential_pardon", "The president"); // valid
	if (f)
	{
		boss.signForm(*f);
		boss.executeForm(*f);
		delete f;
	}
	else
		std::cerr << "Form not found" << std::endl;
}