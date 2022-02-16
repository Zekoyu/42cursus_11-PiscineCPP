/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 16-02-2022  by  `-'                        `-'                  */
/*   Updated: 16-02-2022 17:13 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>

int main()
{
	Span sp = Span(5);

	try
	{
		std::cout << sp.shortestSpan() << std::endl; // not enough to calculate (0)
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}

	sp.addNumber(6);

	try
	{
		std::cout << sp.shortestSpan() << std::endl; // not enough to calculate (1)
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}


	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	Span	bigBoi = Span(10000);
	for (int i = 0; i < 10000; i++)
		bigBoi.addNumber(i * 2);

	std::cout << "Shortest span: " << bigBoi.shortestSpan() << std::endl;
	std::cout << "Longest span: " << bigBoi.longestSpan() << std::endl;

	Span				anotherOne = Span(10);
	std::vector<int>	vect(6, 42);

	anotherOne.addNumber(vect.begin(), vect.end()); // 6 elems
	try
	{
		anotherOne.addNumber(vect.begin(), vect.end()); // 12, impossible
	}
	catch (std::exception &e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}