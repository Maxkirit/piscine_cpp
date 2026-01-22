/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:51:29 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/22 17:16:03 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void):
    ClapTrap()
{
    std::cout << "Nameless Scavtrap constructed." << std::endl;
}

ScavTrap::ScavTrap(std::string name):
    ClapTrap(name)
{
    std::cout << "ScavTrap: " << this->_name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
    this->_name = src._name;
    this->_energyPoints = src._energyPoints;
    this->_hitPoints = src._hitPoints;
    this->_attackDmg = src._attackDmg;
    std::cout << "ScavTrap: " << this->_name << " was copied." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << this->_name << " was destroyed." << std::endl;
}

ScavTrap    &ScavTrap::operator=(ScavTrap const &rhs)
{
    std::cout << "ScavTrap: " << this->_name << " was assigned from " << rhs._name << "." << std::endl;
    this->_name = rhs._name;
    this->_energyPoints = rhs._energyPoints;
    this->_hitPoints = rhs._hitPoints;
    this->_attackDmg = rhs._attackDmg;
    return (*this);
}

void    ScavTrap::guardGate(void) const
{
    static int  mode = 0;
    if (mode == 0)
    {
        std::cout << this->_name << " is now on guard mode." << std::endl;
        mode = 1;
    }
    else
        std::cout << this->_name << " is already on guard mode." << std::endl;
    return ;
}
