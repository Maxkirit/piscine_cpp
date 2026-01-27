/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:32:12 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 11:39:21 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    AMateria* tmp1;
    AMateria* tmp2;
    AMateria* tmp3;
    AMateria* tmp4;
    AMateria* tmp5;
    AMateria* tmp6;
    AMateria *temp;

    tmp = src->createMateria("ice");
    tmp1 = src->createMateria("ice");
    tmp2 = src->createMateria("ice");
    tmp3 = src->createMateria("ice");
    me->equip(tmp);
    tmp4 = src->createMateria("cure");
    tmp5 = src->createMateria("cure");
    tmp6 = src->createMateria("cure");
    me->equip(tmp);
    me->equip(tmp1);
    me->equip(tmp1);
    me->equip(tmp2);
    me->equip(tmp3);
    me->equip(tmp4);
    me->equip(tmp5);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    me->use(3, *bob);
    me->use(4, *bob);
    me->use(5, *bob);
    me->use(6, *bob);
    for (int i = 0; i < 6; i++)
    {
        temp = new Ice();
        me->equip(temp);
        me->unequip(0);
    }

    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());


    delete bob;
    delete me;
    delete src;

    return 0;
}

