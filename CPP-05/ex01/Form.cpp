/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 23:27 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>

Form::Form() : _name("Form"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{ std::cout << "Form default constructor called" << std::endl; }

Form::Form(Form const &f) : _name(f.getName()), _isSigned(f.isSigned()), _gradeToSign(f.getGradeToSign()), _gradeToExecute(f.getGradeToExecute())
{ std::cout << "Form copy constructor called" << std::endl; }

Form::Form(std::string const &name, int const gradeToSign, int const gradeToExecute) :	_name(name),
																						_isSigned(false),
																						_gradeToSign(gradeToSign),
																						_gradeToExecute(gradeToExecute)
{
	std::cout << "Form parameters constructor called" << std::endl;
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw (GradeTooLowException());
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw (GradeTooHighException());
}

Form::~Form() { std::cout << "Form destructor called" << std::endl; }

Form	&Form::operator=(Form const &f)
{
	this->_isSigned = f.isSigned();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Form const &f)

{
	os << "Form named " << f.getName() << ", grade to execute: " << f.getGradeToExecute() << ", grade to sign " << f.getGradeToSign() << ", is signed: " << f.isSigned();
	return (os);
}

bool				Form::isSigned(void) const { return (this->_isSigned); }

std::string const	&Form::getName(void) const { return (this->_name); }

int					Form::getGradeToExecute(void) const { return (this->_gradeToExecute); }

int					Form::getGradeToSign(void) const { return (this->_gradeToSign); }

void				Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw (GradeTooLowException());
	this->_isSigned = true;
}

char const	*Form::GradeTooHighException::what(void) const throw() { return ("Error: Form grade too high (< 1)"); }

char const	*Form::GradeTooLowException::what(void) const throw() { return ("Error: Form grade too low (> 150)"); }
