/* ************************************************************************** */
/*                                                                            */
/*                                  .-.                       .               */
/*                                 / -'                      /                */
/*                  .  .-. .-.   -/--).--..-.  .  .-. .-.   /-.  .-._.)  (    */
/*   By:             )/   )   )  /  /    (  |   )/   )   ) /   )(   )(    )   */
/*                  '/   /   (`.'  /      `-'-''/   /   (.'`--'`-`-'  `--':   */
/*   Created: 05-02-2022  by  `-'                        `-'                  */
/*   Updated: 05-02-2022 16:36 by                                             */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");

	AMateria* tmp;
	AMateria* ice = new Ice();
	AMateria *cure = new Cure(); // declare it before otherwise new Ice() in learn function would leak (since it copies it as the subject mentions)

	src->learnMateria(ice);
	src->learnMateria(cure);
	
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob); // ice action
	me->use(1, *bob); // cure action
	me->unequip(1); // will need to delete tmp (last one we added) otherwise it would leak, as said in the subject: `unequip should not delete the materia`
	me->use(1, *bob); // cure action (should not happen after unequip)
	me->use(0, *bob); // ice action

	delete bob;
	delete me;
	delete src;
	delete ice;
	delete cure;
	delete tmp;
}