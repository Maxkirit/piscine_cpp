/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:24:16 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/24 17:38:13 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void):
    Animal()
{
    this->_type = "Dog";
    std::cout << "Dog constructed." << std::endl;
}

Dog::Dog(std::string name):
    Animal(),
    _name(name)
{
    this->_type = "Dog";
    std::cout << "Dog named " << this->_name << " created." << std::endl;
}

Dog::Dog(Dog const &src):
    Animal(),
    _name(src._name)
{
    this->_type = "Dog";
    std::cout << "Dog ";
    if (this->_name != "")
        std::cout << this->_name;
    std::cout <<  "constructed from copy." << std::endl;
}

Dog::~Dog(void)
{
    std::cout << "Dog destroyed." << std::endl;
}

Dog  &Dog::operator=(Dog const &rhs)
{
    this->_type = rhs._type;
    return (*this);
}

std::string   Dog::getType(void) const
{
    return (this->_type);
}

void    Dog::makeSound(void) const
{
    if (this->_name != "")
        std::cout << this->_name << ": ";
    std::cout << "Woof!" << std::endl;
    return ;
}