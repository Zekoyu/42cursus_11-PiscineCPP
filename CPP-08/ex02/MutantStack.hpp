/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 16-02-2022  by  `-'                        `-'                  */
/*   Updated: 17-02-2022 10:09 by                                             */
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
		typedef typename std::stack<T>::container_type::iterator iterator; // typedef to iterator since main needs stack::iterator
		
		MutantStack() : std::stack<T>() {};
	 	MutantStack(MutantStack const &m) : std::stack<T>(m) {};
		~MutantStack() {};

		MutantStack&	operator=(const MutantStack &m)
		{
			std::stack<T>::operator=(m); // calls parent operator=
			return (*this);
		}

		iterator	begin(void) { return (this->c.begin()); } // c = underlying container

		iterator	end(void) { return (this->c.end()); }
};

#endif