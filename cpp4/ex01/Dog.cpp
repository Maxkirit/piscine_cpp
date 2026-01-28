/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:24:16 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/28 16:08:37 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void):
    Animal("Dog")
{
    this->_mind = new Brain ();
    std::cout << "Dog constructed." << std::endl;
}

Dog::Dog(std::string name):
    Animal("Dog"),
    _name(name)
{
    this->_mind = new Brain ();
    std::cout << "Dog named " << this->_name << " created." << std::endl;
}

Dog::Dog(Dog const &src):
    Animal("Dog"),
    _name(src._name)
{
    this->_mind = new Brain ();
    for (int i = 0; i < 100; i++)
        this->_mind->setIdea(src.getIdea(i), i);
    std::cout << "Dog ";
    if (this->_name != "")
        std::cout << this->_name;
    std::cout <<  "constructed from copy." << std::endl;
}

Dog::~Dog(void)
{
    delete this->_mind;
    std::cout << "Dog destroyed." << std::endl;
}

Dog  &Dog::operator=(Dog const &rhs)
{
    this->_type = rhs._type;
    this->_name = rhs._name;
    delete this->_mind;
    this->_mind = new Brain ();
    for (int i = 0; i < 100; i++)
        this->_mind->setIdea(rhs.getIdea(i), i);
    std::cout << "Dog copied." << std::endl;
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

std::string const   &Dog::getIdea(unsigned int index) const
{
    if (index >= 100)
    {
        std::cout << "Index too high ! Returning index [0]." << std::endl;
        return (this->_mind->getIdea(0));
    }
    return (this->_mind->getIdea(index));
}

void    Dog::setIdea(std::string newIdea, unsigned int index)
{
    if (index >= 100 || index < 0)
    {
        std::cout << "Index out of bounds, either too small or too high. Operation cancelled." << std::endl;
        return ;
    }
    this->_mind->setIdea(newIdea, index);
    return ;
}