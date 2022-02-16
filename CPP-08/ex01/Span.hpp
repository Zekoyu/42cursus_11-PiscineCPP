/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 15-02-2022  by  `-'                        `-'                  */
/*   Updated: 16-02-2022 17:06 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <iterator>

class Span
{
	private:
		int	*_values;
		int	_valuesCount;
		int	_capacity;
	public:
		Span();
		Span(Span const &s);
		Span(int const size);
		~Span();

		Span	&operator=(Span const &s);

		void	addNumber(int const n);

		template <typename Iterator>
		void	addNumber(Iterator start, Iterator end)
		{
			int	newElemsCount = std::distance(start, end);

			if (newElemsCount + this->_valuesCount > this->_capacity)
				throw (SpanAlreadyFullException());
			while (start != end)
			{
				this->_values[this->_valuesCount++] = *start;
				start++;
			}
		}

		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		class SpanAlreadyFullException : public std::exception
		{
			public:
				char const	*what(void) const throw();
		};

		class TooFewNumbersException : public std::exception
		{
			public:
				char const	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, Span const &s);

#endif