/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:26:00 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 10:27:22 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void):
    _type("")
{
    std::cout << "WrongAnimal constructed." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src):
    _type(src._type)
{
    std::cout << "WrongAnimal constructed from copy." << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destroyed." << std::endl;
}

WrongAnimal  &WrongAnimal::operator=(WrongAnimal const &rhs)
{
    this->_type = rhs._type;
    return (*this);
}

std::string   WrongAnimal::getType(void) const
{
    return (this->_type);
}

void    WrongAnimal::makeSound(void) const
{
    if (_type == "")
    {
        std::cout << "**typeless WrongAnimal makes no sound**" << std::endl;
        return ;
    }
    return ;
}