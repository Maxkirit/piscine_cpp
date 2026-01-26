/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:14:30 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 08:11:20 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(void):
    ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDmg = 30;
    std::cout << "Nameless FragTrap constructed." << std::endl;
}

FragTrap::FragTrap(std::string name):
    ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDmg = 30;
    std::cout << "FragTrap: " << this->_name << " constructed." << std::endl;
}

FragTrap::FragTrap(FragTrap const &src)
{
    this->_name = src._name;
    this->_energyPoints = src._energyPoints;
    this->_hitPoints = src._hitPoints;
    this->_attackDmg = src._attackDmg;
    std::cout << "FragTrap: " << this->_name << " was copied." << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap " << this->_name << " was destroyed." << std::endl;
}

FragTrap    &FragTrap::operator=(FragTrap const &rhs)
{
    std::cout << "FragTrap: " << this->_name << " was assigned from " << rhs._name << "." << std::endl;
    this->_name = rhs._name;
    this->_energyPoints = rhs._energyPoints;
    this->_hitPoints = rhs._hitPoints;
    this->_attackDmg = rhs._attackDmg;
    return (*this);
}

void    FragTrap::highFiveGuys(void)
{
    std::cout << this->_name << " is requesting a high five..." << std::endl;
    return ;
}