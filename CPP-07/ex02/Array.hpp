/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 11-02-2022  by  `-'                        `-'                  */
/*   Updated: 11-02-2022 20:03 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;

	public:
		Array() : _array(new T[0]), _size(0)
		{ std::cout << "Array default constructor called" << std::endl; }

		Array(Array const &a) : _array(new T[a.size()]), _size(a.size())
		{
			std::cout << "Array copy constructor called" << std::endl;
			for (unsigned int i = 0; i < a.size(); i++)
				_array[i] = a._array[i];
		}

		Array(unsigned int size) : _array(new T[size]), _size(size)
		{ std::cout << "Array int parameter constructor called" << std::endl; }

		~Array() { delete[] _array; }

		Array	&operator=(Array const &a);

		T		&operator[](unsigned int index)
		{
			if (index > this->_size - 1)
				throw (ArrayIndexOutOfBoundsException());
			return (_array[index]);
		}

		class	ArrayIndexOutOfBoundsException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw() { return ("Index out of range"); }
		};

		unsigned int	size(void) const { return (_size); }
};

// std::ostream	&operator<<(std::ostream &os, Array const &a);

#endif