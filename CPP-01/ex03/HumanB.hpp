#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
private:
	std::string	_name;
	Weapon		*_weapon;
	HumanB();
public:
	HumanB(const std::string &name);
	~HumanB();
	HumanB(const HumanB &w);
	HumanB	&operator=(const HumanB &w);

	void	attack(void) const;

	std::string	getName(void) const;
	void		setName(const std::string &name);

	void		setWeapon(Weapon &w);
};
#endif