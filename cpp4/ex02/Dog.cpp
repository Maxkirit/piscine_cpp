/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:24:16 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 14:00:32 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void):
    AAnimal("Dog")
{
    this->_ideas = new Brain [_brainSize];
    for (int i = 0; i < _brainSize; i++)
        this->_ideas[i].setIdea("");
    std::cout << "Dog constructed." << std::endl;
}

Dog::Dog(std::string name):
    AAnimal("Dog"),
    _name(name)
{
    this->_ideas = new Brain [_brainSize];
    for (int i = 0; i < _brainSize; i++)
        this->_ideas[i].setIdea("");
    std::cout << "Dog named " << this->_name << " created." << std::endl;
}

Dog::Dog(Dog const &src):
    AAnimal("Dog"),
    _name(src._name)
{
    std::cout << "Dog ";
    this->_ideas = new Brain [_brainSize];
    for (int i = 0; i < _brainSize; i++)
        this->_ideas[i].setIdea(src.getIdea(i));
    if (this->_name != "")
        std::cout << this->_name;
    std::cout <<  "constructed from copy." << std::endl;
}

Dog::~Dog(void)
{
    delete [] this->_ideas;
    std::cout << "Dog destroyed." << std::endl;
}

Dog  &Dog::operator=(Dog const &rhs)
{
    this->_type = rhs._type;
    this->_name = rhs._name;
    this->_ideas = new Brain[_brainSize];
    for (int i = 0; i <_brainSize; i++)
        this->_ideas[i].setIdea(rhs.getIdea(i));
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

std::string const   &Dog::getIdea(int index) const
{
    if (index >= _brainSize)
    {
        std::cout << "Index too high ! Returning index [0]." << std::endl;
        return (this->_ideas[0].getIdea());
    }
    return (this->_ideas[index].getIdea());
}

void    Dog::setIdea(std::string newIdea, int index)
{
    if (index >= _brainSize || index < 0)
    {
        std::cout << "Index out of bounds, either too small or too high. Operation cancelled." << std::endl;
        return ;
    }
    this->_ideas[index].setIdea(newIdea);
    return ;
}