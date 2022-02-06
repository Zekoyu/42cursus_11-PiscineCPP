/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 06-02-2022  by  `-'                        `-'                  */
/*   Updated: 06-02-2022 16:21 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <iostream>
#include <stdlib.h>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : Form("robotomy_request", 72, 45), _target("unknown")
{ std::cout << "RobotomyRequestForm default constructor called" << std::endl; }

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &s) : Form(s), _target(s.getTarget())
{ std::cout << "RobotomyRequestForm copy constructor called" << std::endl; }

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("robotomy_request", 72, 45), _target(target)
{ std::cout << "RobotomyRequestForm string parameter constructo called" << std::endl; }

RobotomyRequestForm::~RobotomyRequestForm() { std::cout << "RobotomyRequestForm destructor called" << std::endl; }

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &s)
{
	this->_target = s.getTarget();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, RobotomyRequestForm const &s)

{
	os << "RobotomyRequestForm has target " << s.getTarget();
	return (os);
}


void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->canBeExecuted(executor))
	{
		srand(time(NULL)); // srand initialize the rand() with given seed, here current time

		std::cout << "* VZZZZZZZ *" << std::endl;
		if (rand() % 2) // rand() generates a number between 0 and RAND_MAX (at least 32767)
		{
			std::cout << "The robotomy succeeded " << this->getTarget() << " is now robotomized" << std::endl;
		}
		else
		{
			std::cout << "* Cracking noise *" << std::endl;
			std::cout << "The robotomy failed, " << this->getTarget() << " never woke up ..." << std::endl;
		}
	}
} 


std::string	RobotomyRequestForm::getTarget(void) const { return (this->_target); }

