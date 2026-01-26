/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:02:49 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 13:59:50 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal(void):
    _type("")
{
    std::cout << "Animal constructed." << std::endl;
}

AAnimal::AAnimal(std::string type):
    _type(type)
{
    std::cout << "Animal " << this->_type << " created." << std::endl;
}

AAnimal::AAnimal(AAnimal const &src):
    _type(src._type)
{
    std::cout << "Animal constructed from copy." << std::endl;
}

AAnimal::~AAnimal(void)
{
    std::cout << "Animal destroyed." << std::endl;
}

AAnimal  &AAnimal::operator=(AAnimal const &rhs)
{
    this->_type = rhs._type;
    return (*this);
}
std::string   AAnimal::getType(void) const
{
    return (this->_type);
}

void    AAnimal::makeSound(void) const
{
    if (_type == "")
    {
        std::cout << "**typeless Animal makes no sound**" << std::endl;
        return ;
    }
    return ;
}