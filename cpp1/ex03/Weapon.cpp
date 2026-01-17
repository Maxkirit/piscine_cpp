/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:39:35 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/17 16:50:53 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon():
	_type("none")
{	
}

Weapon::Weapon(std::string type):
	_type(type)
{
	std::cout << "Weapon " << this->_type << " created." << std::endl;
}

Weapon::Weapon(void)
{
	std::cout << "Weapon " << this->_type << " deleted." << std::endl;
}

void	Weapon::setType(std::string newType)
{
	if (newType.compare(""))
		return ;
	this->_type = newType;
	return ;
}
std::string const	&Weapon::getType(void)
{
	return (this->_type);
}