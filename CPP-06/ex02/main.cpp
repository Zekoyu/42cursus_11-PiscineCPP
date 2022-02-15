/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 09-02-2022  by  `-'                        `-'                  */
/*   Updated: 11-02-2022 11:36 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Bases.hpp"

#include <stdlib.h>
#include <time.h>

Base	*generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			std::cout << "Created type A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Created type B" << std::endl;
			return (new B());
		case 2:
			std::cout << "Created type C" << std::endl;
			return (new C());
		default: // should not execute, but who knows
			std::cout << "Created type C" << std::endl;
			return (new C());
	}
}

// If the cast fails and new-type is a pointer type, it returns a null pointer of that type.
void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

// Otherwise, the runtime check fails. If the dynamic_cast is used on pointers, 
// the null pointer value of type new-type is returned. If it was used on references, the exception std::bad_cast is thrown.
void	identify(Base &p)
{
	try
	{
		(void) dynamic_cast<A&>(p); // "expression result unused"
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception &e)	{ } // If catch, go to next test, could use std::bad_cast but need to include typeinfo
	
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception &e)	{ }

	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
		std::cout << "Couldn't identify type, you should never see this message." << std::endl;
	}
}

int main()
{
	srand(time(NULL));

	Base *b = generate();
	identify(b);

	srand(time(NULL) + 2.8);
	Base *c = generate();
	identify(*c);

	delete b;
	delete c;
}