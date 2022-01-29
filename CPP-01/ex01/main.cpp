#include "Zombie.hpp"

int main()
{
	int zombieCount = 6;

	Zombie	*horde = zombieHorde(zombieCount, "Gigachad");

	for (int i = 0; i < zombieCount; i++)
		horde[i].announce();

	delete[] horde;

	return (0);
}