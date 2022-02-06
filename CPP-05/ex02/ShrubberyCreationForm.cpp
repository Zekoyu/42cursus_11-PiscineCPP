/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 06-02-2022  by  `-'                        `-'                  */
/*   Updated: 06-02-2022 15:57 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("shruberry_creation", 145, 137), _target("unknown")
{ std::cout << "ShrubberyCreationForm default constructor called" << std::endl; }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &s) : Form(s), _target(s.getTarget())
{ std::cout << "ShrubberyCreationForm copy constructor called" << std::endl; }

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("shruberry_creation", 145, 137), _target(target)
{ std::cout << "ShrubberyCreationForm string parameter constructo called" << std::endl; }

ShrubberyCreationForm::~ShrubberyCreationForm() { std::cout << "ShrubberyCreationForm destructor called" << std::endl; }

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &s)
{
	this->_target = s.getTarget();
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, ShrubberyCreationForm const &s)

{
	os << "ShrubberyCreationForm has target " << s.getTarget();
	return (os);
}

std::string const	shrubberiesAscii =
"   ^                ^\n"
"  /|\\         ^    /|\\            ^\n"
"     ^    ^  /|\\         ^       /|\\   ^\n"
" ^  /|\\  /|\\      ^     /|\\     ^	   /|\\\n"
"/|\\              /|\\           /|\\\n";

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->canBeExecuted(executor))
	{
		std::ofstream	file;
		
		file.open((this->getTarget() + "_shrubbery").c_str(), std::ios::out);
		if (file.good())
			file << shrubberiesAscii;
		file.close();
	}
} 


std::string	ShrubberyCreationForm::getTarget(void) const { return (this->_target); }

