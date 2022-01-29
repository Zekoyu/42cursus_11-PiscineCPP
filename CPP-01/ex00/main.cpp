#include "Zombie.hpp"

int main()
{
	Zombie z1 = Zombie("Chad");
	Zombie *z2 = newZombie("Nab");
	randomChump("Pouic");

	z2->announce();

	delete(z2);
	return (0);
}