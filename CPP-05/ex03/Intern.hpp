/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 06-02-2022  by  `-'                        `-'                  */
/*   Updated: 06-02-2022 18:03 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#define KNOWN_FORMS_COUNT 3

class Intern
{
	private:
		static std::string const	_knownFormsTypes[KNOWN_FORMS_COUNT];
		static Form	*				(*_knownFormsFuncs[KNOWN_FORMS_COUNT])(std::string const &target);

		static Form	*createPresidentialPardonForm(std::string const &target);
		static Form	*createRobotomyRequestForm(std::string const &target);
		static Form	*createShrubberyCreationForm(std::string const &target);
	public:
		Intern();
		Intern(Intern const &i);
		~Intern();

		Intern	&operator=(Intern const &i);

		Form	*makeForm(std::string const &name, std::string const &target) const;

};

#endif