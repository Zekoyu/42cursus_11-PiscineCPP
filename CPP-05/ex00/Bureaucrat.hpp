/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 21:00 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		std::string	const	_name;
		int					_grade;

		void				setGrade(int const grade);
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &b);
		Bureaucrat(std::string const &name, int const grade);
		~Bureaucrat();

		Bureaucrat	&operator=(Bureaucrat const &b);

		class GradeTooHighException : public std::exception // All C++ exceptions inhering from std::exception 
		{
			public:
				virtual char const *what(void) const throw(); // throws nothing, otherwise if we had a throw in a catch, it would be a mess
				// Virtual keyword or not is exactly the same in child class, however some compilers will complain, I should add it everytime then
		};

		class GradeTooLowException : public std::exception // All C++ exceptions inhering from std::exception 
		{
			public:
				virtual char const *what(void) const throw();
		};

		std::string const	&getName(void) const;
		int					getGrade(void) const;

		void				gradeUp(void);
		void				gradeDown(void);
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &b);

#endif