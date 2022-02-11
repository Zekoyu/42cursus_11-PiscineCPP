/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 11-02-2022  by  `-'                        `-'                  */
/*   Updated: 11-02-2022 18:49 by                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

// Need to implement templates along with declaration because the compiler creates a class with the given type
// so it needs to know implementation, some can find it in another file, but most of them don't
template <typename T>
void	swap(T &lhs, T &rhs)
{
	/*
	tmp cannot be a reference since it's basically an alias, it would always point to lhs
	when we do lhs = rhs then it will point to rhs
	*/
	T	tmp = lhs; 

	lhs = rhs;
	rhs = tmp;
}

template <typename T>
T	min(T &lhs, T &rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

template <typename T>
T	max(T &lhs, T &rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

#endif