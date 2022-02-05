/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 23:26 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string	const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExecute;
	public:
		Form();
		Form(Form const &f);
		Form(std::string const &name, int const gradeToSign, int const gradeToExecute);
		~Form();

		Form	&operator=(Form const &f);

		void	beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual char const *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual char const *what(void) const throw();
		};

		bool				isSigned(void) const;
		std::string const	&getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
};

std::ostream	&operator<<(std::ostream &os, Form const &f);

#endif