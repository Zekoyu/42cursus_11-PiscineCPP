/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 15-02-2022  by  `-'                        `-'                  */
/*   Updated: 16-02-2022 13:43 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <algorithm>

class	ItemNotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw() { return ("Item not found"); }
};

// Container::Iterator = iterator of the given type (eg. std::vector<int>::Iterator	)
template<typename Container>
int	&easyfind(Container &c, int n) // should only be called with containers with iterators as argument
{
	/*typename Container::iterator	it = c.begin();

	while (it != c.end()) // https://stackoverflow.com/questions/6673762/why-is-used-with-iterators-instead-of
	{
		if (*it == n)
			return (*it);
		it++;
	}*/

	typename Container::iterator it = std::find(c.begin(), c.end(), n); // typename avoids taking Container for a lvalue (eg. member, function etc.)
	if (it != c.end())
		return (*it);
	throw (ItemNotFoundException());
}

#endif