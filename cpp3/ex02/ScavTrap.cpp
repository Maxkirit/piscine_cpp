/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:51:29 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 08:10:18 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void):
    ClapTrap(),
    _guardMode(false)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDmg = 20;
    std::cout << "Nameless Scavtrap constructed." << std::endl;
}

ScavTrap::ScavTrap(std::string name):
    ClapTrap(name),
    _guardMode(false)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDmg = 20;
    std::cout << "ScavTrap: " << this->_name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
    this->_name = src._name;
    this->_energyPoints = src._energyPoints;
    this->_hitPoints = src._hitPoints;
    this->_attackDmg = src._attackDmg;
    this->_guardMode = false; //here, we copy initialize a new instance so state shouldn't be copied.
    std::cout << "ScavTrap: " << this->_name << " was copied." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " <<  this->_name << " was destroyed." << std::endl;
}

ScavTrap    &ScavTrap::operator=(ScavTrap const &rhs)
{
    std::cout << "ScavTrap: " << this->_name << " was assigned from " << rhs._name << "." << std::endl;
    this->_name = rhs._name;
    this->_energyPoints = rhs._energyPoints;
    this->_hitPoints = rhs._hitPoints;
    this->_attackDmg = rhs._attackDmg;
    this->_guardMode = rhs._guardMode; //we are copying everything here, including state.
    return (*this);
}

void    ScavTrap::guardGate(void)
{
    if (this->_hitPoints == 0)
    {
        std::cout << this->_name << " has fainted and can't do anything." << std::endl;
    }
    if (this->_guardMode == false)
    {
        std::cout << this->_name << " is now on guard mode." << std::endl;
        this->_guardMode = true;
    }
    else
        std::cout << this->_name << " is already on guard mode." << std::endl;
    return ;
}

bool    ScavTrap::getGuardMode(void) const
{
    return (this->_guardMode);
}
