#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
	std::string	_name;
public:
	Zombie();
	Zombie(const std::string name);
	Zombie(const Zombie& z);
	~Zombie();
	Zombie& operator= (const Zombie& z);

	std::string		getName(void) const;
	void			setName(std::string);

	void			announce(void) const;
};

Zombie	*zombieHorde(int n, std::string name);

#endif