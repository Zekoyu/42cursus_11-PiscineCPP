/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 17-02-2022  by  `-'                        `-'                  */
/*   Updated: 17-02-2022 10:15 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <vector>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Stack top: " << mstack.top() << std::endl;
	std::cout << "Stack size: " << mstack.size() << std::endl;
	mstack.pop();
	std::cout << "Stack size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << "Val: " << *it << std::endl;
		++it;
	}

	std::cout << std::endl;
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(17);
	std::cout << "Vector last: " << vec.back() << std::endl;
	std::cout << "Vector size: " << vec.size() << std::endl;
	vec.pop_back();
	std::cout << "Vector size: " << vec.size() << std::endl;
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	vec.push_back(0);
	std::vector<int>::iterator vit = vec.begin();
	std::vector<int>::iterator vite = vec.end();
	++vit;
	--vit;
	while (vit != vite)
	{
		std::cout << "Val: " << *vit << std::endl;
		++vit;
	}
}