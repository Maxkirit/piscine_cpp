/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:41:30 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/17 17:11:41 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name):
	_name(name),
	_weaponp(0)
{
	std::cout << "HumanB " << this->_name << " created." << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB " << this->_name << "was destroyed." << std::endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->_weaponp = &weapon;
}

void	HumanB::attack(void) const
{
	if (this->_weaponp == 0)
	{
		std::cout << this->_name << " tries to bite its target..." << std::endl;
		return ;
	}
	std::cout << this->_name << " attacked with " << this->_weaponp->getType() << "!" << std::endl;
	return ;
}