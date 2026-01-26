/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:28:09 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 10:39:18 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void):
    WrongAnimal()
{
    this->_type = "WrongCat";
    std::cout << "WrongCat constructed." << std::endl;
}

WrongCat::WrongCat(WrongCat const &src):
    WrongAnimal()
{
    this->_type = src._type;
    std::cout << "WrongCat constructed from copy." << std::endl;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destroyed." << std::endl;
}

WrongCat  &WrongCat::operator=(WrongCat const &rhs)
{
    this->_type = rhs._type;
    return (*this);
}

std::string   WrongCat::getType(void) const
{
    return (this->_type);
}

void    WrongCat::makeSound(void) const
{
    if (this->_name != "")
        std::cout << this->_name << ": ";
    std::cout << "Woow this is weird!" << std::endl;
    return ;
}