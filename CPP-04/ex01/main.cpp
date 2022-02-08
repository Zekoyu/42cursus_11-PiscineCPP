/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 04-02-2022  by  `-'                        `-'                  */
/*   Updated: 07-02-2022 14:55 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal meta = Animal();
	Animal* j = new Dog();
	Animal i;

	i = Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i.getType() << " " << std::endl;

	i.makeSound(); // cat sound
	j->makeSound(); // dog sound
	meta.makeSound(); // animal sound

	// fsanitize enabled to check for brain leaks
	
	Dog	d1 = Dog();
	d1.setIdea(0, "I should probably invest in monki NFT");
	
	Dog d2 = Dog();
	std::cout << "d1 idea[0]: " << d1.getIdea(0) << std::endl;
	std::cout << "d2 idea[0]: " << d2.getIdea(0) << std::endl;
	d2 = d1; // Deep copy d2
	std::cout << "copied d1 idea[0]: " << d1.getIdea(0) << std::endl;
	std::cout << "copied d2 idea[0]: " << d2.getIdea(0) << std::endl;
	d1.setIdea(0, "Or not"); // Then change d1 to check if deep copy was successfull
	std::cout << "d1 idea[0]: " << d1.getIdea(0) << std::endl; // should be "I should probably invest in monki NFT" and not "Or not"
	std::cout << "d2 idea[0]: " << d2.getIdea(0) << std::endl; // should be "Or not"
	
	delete j; // Of course need to free new, check Cat to see for Brain leaks
}