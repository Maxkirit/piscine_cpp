/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:34:02 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/17 16:16:54 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie():
    _name("Unknown")
{
}

Zombie::Zombie(std::string name):
	_name(name)
{
	std::cout << "Zombie '" << this->_name << "' was created." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie '" << this->_name << "' was destroyed." << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void    Zombie::setName(std::string name)
{
    if (name.compare(""))
        this->_name = name;
    return ;
}