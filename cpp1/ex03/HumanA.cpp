/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:40:46 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/17 17:02:40 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon weapon):
	_name(name),
	_weapon(weapon)
{
	std::cout << "HumanA " << this->_name;
	std::cout << " created, armed with " << this->_weapon.getType() << "." << std::endl;
}
HumanA::~HumanA(void)
{
	std::cout << "HumanA " << this->_name << " destroyed." << std::endl;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacked with " << this->_weapon.getType() << "!" << std::endl;
	return ;
}