/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 11-02-2022  by  `-'                        `-'                  */
/*   Updated: 11-02-2022 18:56 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Iter.hpp"

void	decrement_num(int &num)
{
	num--;
}

void	print_array(int *arr, int len)
{
	for (int i = 0; i < len; i++)
		std::cout << arr[i] << std::endl;
}

void	print_num(int &n)
{
	std::cout << "Print num: " << n << std::endl;
}

int main()
{
	int	test[] = {1, 2, 3, 4, 5};

	print_array(test, 5);
	std::cout << std::endl;

	iter(test, 5, &decrement_num);

	print_array(test, 5);
	std::cout << std::endl;
	
	iter(test, 5, &print_num);
}