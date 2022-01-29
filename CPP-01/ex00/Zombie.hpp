#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
	std::string	_name;
	Zombie();
public:
	Zombie(const std::string name);
	Zombie(const Zombie& z);
	~Zombie();
	Zombie& operator= (const Zombie& z);

	std::string		getName(void) const;
	void			setName(std::string);

	void			announce(void) const;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif