/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 06-02-2022  by  `-'                        `-'                  */
/*   Updated: 06-02-2022 18:11 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

Intern::Intern() { std::cout << "Intern default constructor called" << std::endl; }

Intern::Intern(Intern const &i)
{
	(void) i;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern() { std::cout << "Intern destructor called" << std::endl; }

Intern	&Intern::operator=(Intern const &i)
{
	(void) i;
	return (*this);
}

// Returns null if not found
Form	*Intern::makeForm(std::string const &name, std::string const &target) const
{
	Form	*form = NULL;
	for (int i = 0; i < KNOWN_FORMS_COUNT; i++)
	{
		if (Intern::_knownFormsTypes[i] == name)
		{
			form = Intern::_knownFormsFuncs[i](target);
			std::cout << "Intern creates form " << form->getName() << std::endl;
			break ;
		}
	}
	return (form);
}

std::string const	Intern::_knownFormsTypes[KNOWN_FORMS_COUNT] = {
	"presidential_pardon",
	"robotomy_request",
	"shrubbery_creation"
};

Form	*(*Intern::_knownFormsFuncs[KNOWN_FORMS_COUNT])(std::string const &target) = { // Function pointer
	&Intern::createPresidentialPardonForm,
	&Intern::createRobotomyRequestForm,
	&Intern::createShrubberyCreationForm
};

Form	*Intern::createPresidentialPardonForm(std::string const &target) { return (new PresidentialPardonForm(target)); }

Form	*Intern::createRobotomyRequestForm(std::string const &target) { return (new RobotomyRequestForm(target)); }

Form	*Intern::createShrubberyCreationForm(std::string const &target) { return (new ShrubberyCreationForm(target)); }
