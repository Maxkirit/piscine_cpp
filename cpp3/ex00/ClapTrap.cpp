/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:23:47 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/22 16:47:05 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
    _name(""),
    _hitPoints(10),
    _energyPoints(10),
    _attackDmg(3)
{
    std::cout << "Nameless ClapTrap constructed." << std::endl;
}

ClapTrap::ClapTrap(std::string name):
    _name(name),
    _hitPoints(10),
    _energyPoints(10),
    _attackDmg(3)
{
   std::cout << "ClapTrap " << this->_name << " constructed." << std::endl; 
}

ClapTrap::ClapTrap(ClapTrap const &src):
    _name(src._name),
    _hitPoints(src._hitPoints),
    _energyPoints(src._energyPoints),
    _attackDmg(src._attackDmg)
{
    std::cout << "ClapTrap copy constructor called from instance named: " << src._name << "." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor called on " << this->_name << "." << std::endl;
}

ClapTrap    &ClapTrap::operator=(ClapTrap const &rhs)
{
    std::cout << "Assigning " << rhs._name << " to " << this->_name << "." << std::endl;
    this->_name = rhs._name;
    this->_energyPoints = rhs._energyPoints;
    this->_hitPoints = rhs._hitPoints;
    this->_attackDmg = rhs._attackDmg;
    return (*this);
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

int ClapTrap::getEnergy(void) const
{
    return (this->_energyPoints);
}

int ClapTrap::getDmg(void) const
{
    return (this->_attackDmg);
}

int ClapTrap::getHitPoints(void) const
{
    return (this->_hitPoints);
}

void    ClapTrap::attack(const std::string &target)
{
    if (this->_hitPoints == 0)
    {
        std::cout << this->_name << " is KO." << std::endl;
        return ;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << this->_name << " is exhausted and can't do anything!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDmg << " points of damage!" << std::endl;
    this->_energyPoints--;
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << this->_name << " is already KO." << std::endl;
        return ;       
    }
    std::cout << this->_name << " took " << amount << " points of damage." << std::endl;
    this->_hitPoints -= amount;
    if (this->_hitPoints < 0)
    {
        std::cout << this->_name << " has fainted !" << std::endl;
        this->_hitPoints = 0;
        return ;
    }
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << this->_name << " is KO." << std::endl;
        return ;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << this->_name << " is exhausted and can't do anything!" << std::endl;
        return ;
    }
    if (this->_hitPoints == 10)
    {
        std::cout << this->_name << " is full life." << std::endl;
        return ;
    }
    if (this->_hitPoints + amount > 10)
        amount = 10 - this->_hitPoints;
    this->_energyPoints--;
    std::cout << this->_name << " gained " << amount << " hit points." << std::endl;
    this->_hitPoints +=  amount;
    return ;
}