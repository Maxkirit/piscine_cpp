/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:13:55 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 18:54:02 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void):
    _materiaNum(0)
{
    for (int i = 0; i < 4; i++)
        this->_slots[i] = 0;
}
MateriaSource::MateriaSource(MateriaSource const &src):
    _materiaNum(src._materiaNum)
{
    for (int i = 0; i < 4; i++)
        this->_slots[i] = src._slots[i]->clone();
}

MateriaSource::~MateriaSource(void)
{
    for (unsigned int i = 0; i < this->_materiaNum; i++)
        delete this->_slots[i]; 
}

MateriaSource   &MateriaSource::operator=(MateriaSource const &rhs)
{
    this->_materiaNum = rhs._materiaNum;
    for (int i = 0; i < 4; i++)
        this->_slots[i] = rhs._slots[i]->clone();
    return (*this);
}

void    MateriaSource::learnMateria(AMateria *m)
{
    if (this->inSlots(m))
    {
        std::cout << "Materia already known.." << std::endl;
        return ;
    }
    if (this->_materiaNum == 4)
    {
        std::cout << "Source full." << std::endl;
        delete m;
        return ;
    }
    this->_slots[this->_materiaNum] = m;
    this->_materiaNum++;
    return ;
}

AMateria    *MateriaSource::createMateria(std::string const &type)
{
    for (unsigned int i = 0; i < this->_materiaNum; i++)
    {
        if (this->_slots[i]->getType() == type)
            return (this->_slots[i]->clone());
    }
    std::cout << "No materia in source that match '" << type << "'." << std::endl;
    return (0);
}

bool    MateriaSource::inSlots(AMateria *m) const
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_slots[i] == m)
            return (true);
    }
    return (false);
}
