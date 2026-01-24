/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:22:57 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/24 17:37:12 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void):
    Animal()
{
    this->_type = "Cat";
    std::cout << "Cat constructed." << std::endl;
}

Cat::Cat(std::string name):
    Animal(),
    _name(name)
{
    this->_type = "Cat";
    std::cout << "Cat named " << this->_name << " created." << std::endl;
}

Cat::Cat(Cat const &src):
    Animal(),
    _name(src._name)
{
    this->_type = "Cat";
    std::cout << "Cat ";
    if (this->_name != "")
        std::cout << this->_name;
    std::cout <<  "constructed from copy." << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "Cat destroyed." << std::endl;
}

Cat  &Cat::operator=(Cat const &rhs)
{
    this->_type = rhs._type;
    return (*this);
}

std::string   Cat::getType(void) const
{
    return (this->_type);
}

void    Cat::makeSound(void) const
{
    if (this->_name != "")
        std::cout << this->_name << ": ";
    std::cout << "Meow!" << std::endl;
    return ;
}