/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 15:48 by                                             */
/*                                                                            */
/* ************************************************************************** */
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include <iostream>

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_knownMaterias[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &m);
		~MateriaSource();

		MateriaSource	&operator=(MateriaSource const &m);

		void		learnMateria(AMateria *a);
		AMateria	*createMateria(std::string const &type);
		int			getKnownMateriasCount(void) const;
};

std::ostream	&operator<<(std::ostream &os, MateriaSource const &m);

#endif