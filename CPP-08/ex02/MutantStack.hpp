/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 16-02-2022  by  `-'                        `-'                  */
/*   Updated: 16-02-2022 22:24 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
		
	public:
		// container_type = underlying / base container type (default deque), deque::iterator = random access iterator of deque
		typedef typename std::stack<T>::container_type::iterator it;
		
		MutantStack() : std::stack<T>() {};
	 	MutantStack(MutantStack const &m) : std::stack<T>(srmc) {};
		~MutantStack() {};

		MutantStack&	operator=(const MutantStack & src)
		{
			std::stack<T>::operator=(src); // calls parent operator=
			return (*this);
		}

		it	begin(void) { return (this->c.begin()); } // c = underlying container

		it	end(void) { return (this->c.end()); }
};

#endif