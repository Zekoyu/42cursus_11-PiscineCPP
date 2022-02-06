/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 06-02-2022  by  `-'                        `-'                  */
/*   Updated: 06-02-2022 16:05 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <stdlib.h>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm() : Form("presidential_pardon", 25, 5), _target("unknown")
{ std::cout << "PresidentialPardonForm default constructor called" << std::endl; }

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &s) : Form(s), _target(s.getTarget())
{ std::cout << "PresidentialPardonForm copy constructor called" << std::endl; }

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form("presidential_pardon", 25, 5), _target(target)
{ std::cout << "PresidentialPardonForm string parameter constructor called" << std::endl; }

PresidentialPardonForm::~PresidentialPardonForm() { std::cout << "PresidentialPardonForm destructor called" << std::endl; }

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &s)
{
	this->_target = s.getTarget();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, PresidentialPardonForm const &s)

{
	os << "PresidentialPardonForm has target " << s.getTarget();
	return (os);
}


void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->canBeExecuted(executor))
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblerox" << std::endl;
} 


std::string	PresidentialPardonForm::getTarget(void) const { return (this->_target); }

