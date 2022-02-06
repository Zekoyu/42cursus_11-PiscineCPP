/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 06-02-2022 16:08 by                                             */
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
	protected:
		Form();
		bool			canBeExecuted(Bureaucrat const &executor) const;
	public:
		Form(Form const &f);
		Form(std::string const &name, int const gradeToSign, int const gradeToExecute);
		virtual ~Form();

		Form	&operator=(Form const &f);

		void			beSigned(Bureaucrat const &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0; // https://stackoverflow.com/questions/2089083/pure-virtual-function-with-implementation, execute can be implemented directly in Form

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

		class FormNotSignedException : public std::exception
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