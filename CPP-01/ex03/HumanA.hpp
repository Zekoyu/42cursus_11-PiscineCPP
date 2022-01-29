#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
private:
	std::string	_name;
	Weapon		&_weapon;
public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA();
	HumanA(const HumanA &w);
	HumanA	&operator=(const HumanA &w);

	void	attack(void) const;

	std::string	getName(void) const;
	void		setName(const std::string &name);
};
#endif