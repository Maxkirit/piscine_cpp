/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:02:49 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 11:22:04 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void):
    _type("")
{
    std::cout << "Animal constructed." << std::endl;
}

Animal::Animal(std::string type):
    _type(type)
{
    std::cout << "Animal " << this->_type << " created." << std::endl;
}

Animal::Animal(Animal const &src):
    _type(src._type)
{
    std::cout << "Animal constructed from copy." << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Animal destroyed." << std::endl;
}

Animal  &Animal::operator=(Animal const &rhs)
{
    this->_type = rhs._type;
    return (*this);
}

std::string   Animal::getType(void) const
{
    return (this->_type);
}

void    Animal::makeSound(void) const
{
    if (_type == "")
    {
        std::cout << "**typeless animal makes no sound**" << std::endl;
        return ;
    }
    return ;
}