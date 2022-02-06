/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 06-02-2022  by  `-'                        `-'                  */
/*   Updated: 06-02-2022 15:56 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm();
		std::string	_target;
	public:
		
		RobotomyRequestForm(RobotomyRequestForm const &s);
		RobotomyRequestForm(std::string const &target);
		~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(RobotomyRequestForm const &s);

		virtual void	execute(Bureaucrat const &executor) const;
		std::string		getTarget(void) const;
};

std::ostream	&operator<<(std::ostream &os, RobotomyRequestForm const &s);

#endif