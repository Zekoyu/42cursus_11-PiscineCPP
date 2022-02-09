/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 09-02-2022  by  `-'                        `-'                  */
/*   Updated: 09-02-2022 18:04 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <iostream>
#include <stdint.h>

struct Data // struct = default public, class = default private
{
	int	someData;
	int	someOtherData;
};

std::ostream	&operator<<(std::ostream &os, Data const &d)

{
	std::cout << "Some data: " << d.someData << ", some other data: " << d.someOtherData;
	return (os);
}

// just read the memory as uintptr now
uintptr_t	serialize(Data *ptr) { return (reinterpret_cast<uintptr_t>(ptr)); }

// then read it back as Data *
Data		*deserialize(uintptr_t ptr) { return (reinterpret_cast<Data*>(ptr)); }


int main()
{
	srand(time(NULL)); // initialize random seed

	Data 		*d = new Data();

	d->someData = rand() % 100;
	d->someOtherData = 42;
	
	uintptr_t	p = serialize(d);
	
	std::cout << "Before: " << *d << std::endl;
	std::cout << "Serialized data: " << p << std::endl;
	Data *d2 = deserialize(p);
	std::cout << "After deserialization: " << *d2 << std::endl;
	std::cout << "Base address: " << d << ", deserialized address: " << d2 << std::endl; // should be the same

	delete d;
}