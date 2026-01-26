/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:23:46 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 08:19:49 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void):
	ClapTrap(),
	ScavTrap(),
	FragTrap()
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDmg = FragTrap::_attackDmg;
	std::cout << "Nameless DiamondTrap constructed." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name),
	ScavTrap(name),
	FragTrap(name)
{
	this->_name = name;
    ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDmg = FragTrap::_attackDmg;
	std::cout <<  "DiamondTrap " << this->_name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src):
	ClapTrap(src.ClapTrap::_name),
	ScavTrap(src._name),
	FragTrap(src._name)
{
	this->_name = src._name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDmg = FragTrap::_attackDmg;
	std::cout << "DiamondTrap" << this->_name << " copied." << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " was destroyed." << std::endl;
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "My name is " << this->_name << " and my ClapTrap name is: " << this->ClapTrap::_name << std::endl;
	return ;
}

void    DiamondTrap::attack(std::string const &target)
{
	return (ScavTrap::attack(target));
}