/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 30-01-2022  by  `-'                        `-'                  */
/*   Updated: 31-01-2022 14:00 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static int const	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const &f);
		~Fixed();

		Fixed	&operator=(Fixed const &f);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed const	&min(Fixed const &lhs, Fixed const &rhs);
		static Fixed const	&max(Fixed const &lhs, Fixed const &rhs);

		bool	operator<(Fixed const &f) const;
		bool	operator<=(Fixed const &f) const;
		bool	operator>(Fixed const &f) const;
		bool	operator>=(Fixed const &f) const;
		bool	operator==(Fixed const &f) const;
		bool	operator!=(Fixed const &f) const;
		
		Fixed	operator+(Fixed const &f) const;
		Fixed	operator-(Fixed const &f) const;
		Fixed	operator/(Fixed const &f) const;
		Fixed	operator*(Fixed const &f) const;

		Fixed	operator++();		// Prefix
		Fixed	operator++(int);	// Postfix
		Fixed	operator--();
		Fixed	operator--(int);
};

std::ostream	&operator<<(std::ostream &os, Fixed const &f);

#endif