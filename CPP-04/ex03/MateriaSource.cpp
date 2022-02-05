/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 21:12 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_knownMaterias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &m)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (m._knownMaterias[i] != NULL)
			this->_knownMaterias[i] = m._knownMaterias[i]->clone();
		else
			this->_knownMaterias[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_knownMaterias[i]; // delete is like free in C, if NULL is passed it does nothing
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &m)
{
	for (int i = 0; i < 4; i++)
	{
		if (m._knownMaterias[i] != NULL)
			this->_knownMaterias[i] = m._knownMaterias[i]->clone();
		else
			this->_knownMaterias[i] = NULL;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, MateriaSource const &m)

{
	os << "MateriaSource with " << m.getKnownMateriasCount() << " known materias";
	return (os);
}

void		MateriaSource::learnMateria(AMateria *a)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_knownMaterias[i] == NULL)
		{
			this->_knownMaterias[i] = a->clone();
			break;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
		if (this->_knownMaterias[i] && this->_knownMaterias[i]->getType() == type)
			return (this->_knownMaterias[i]->clone());
	return (NULL);
}

int			MateriaSource::getKnownMateriasCount(void) const
{
	int count = 0;
	for (int i = 0; i < 4; i++)
		if (this->_knownMaterias[i])
			count++;
	return (count);
}