/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:06:54 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 11:43:55 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void):
    _name(""),
    _equipCount(0),
    _discardCount(0)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = 0;
}

Character::Character(std::string name):
    _name(name),
    _equipCount(0),
    _discardCount(0)
{
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = 0;
}

Character::Character(Character const &src):
    _name(src._name),
    _equipCount(src._equipCount),
    _discardCount(src._discardCount)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
    }
}

Character::~Character(void)
{
    for (unsigned int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            delete _inventory[i];
    }
    for (unsigned int j = 0; j < this->_discardCount; j++)
        delete _discard[j];
}

Character   &Character::operator=(Character const &rhs)
{
    this->_name = rhs._name;
    this->_equipCount = rhs._equipCount;
    for (unsigned int i = 0; i < 4; i++)
    {
        if (this->_inventory[i])
            delete _inventory[i];
    }
    for (unsigned int i = 0; i < 4; i++)
    {
        if (rhs._inventory[i])
            this->_inventory[i] = rhs._inventory[i]->clone();
    }
    return (*this);
}

std::string const   &Character::getName(void) const
{
    return (this->_name);
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "index out of range [0-3]." << std::endl;
        return ;
    }
    if (!this->_inventory[idx])
    {
        std::cout << "Nothing equipped on this slot." << std::endl;
        return ;
    }
    return (this->_inventory[idx]->use(target));
}


bool    Character::inInventory(AMateria *m) const{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == m)
            return (true);
    }
    return (false);
}

//save the pointer passed as arg to allow delete if full
void    Character::equip(AMateria *m)
{
    if (this->inInventory(m))
    {
        std::cout << "Materia already equipped." << std::endl;
        return ;
    }
    if (_equipCount == 4)
    {
        std::cout << "Inventory full." << std::endl;
        if (this->_discardCount < 1024)
        {
            this->_discard[this->_discardCount] = m;
            this->_discardCount++;
        }
        else
            delete m;
        return ;
    }
    if (!m)
    {
        std::cout << "Can't equip null materia." <<std::endl;
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == 0)
        {
            this->_inventory[i] = m;
            this->_equipCount++;
            return ;
        }
    }
    if (!this->inInventory(m))
        delete m;
    return ;
}

//save the pointer passed as arg to allow delete if discard full
void    Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
    {
        std::cout << "index out of range [0-3]." << std::endl;
        return ;
    }
    if (!this->_inventory[idx])
    {
        std::cout << "Nothing equipped on this slot." << std::endl;
        return ;
    }
    if (this->_discardCount >= 1023)
    {
        std::cout << "you have reached the limits of unequips/char. check _discardCount and end program." << std::endl;
        return ;
    }
    this->_discard[_discardCount] = this->_inventory[idx];
    this->_discardCount++;
    this->_inventory[idx] = 0;
    this->_equipCount--;
    return ;
}
