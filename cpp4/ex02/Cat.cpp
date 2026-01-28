/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:22:57 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/28 16:08:42 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void):
    AAnimal("Cat")
{
    this->_mind = new Brain ();
    std::cout << "Cat constructed." << std::endl;
}

Cat::Cat(std::string name):
    AAnimal("Cat"),
    _name(name)
{
    this->_mind = new Brain ();
    std::cout << "Cat named " << this->_name << " created." << std::endl;
}

Cat::Cat(Cat const &src):
    AAnimal("Cat"),
    _name(src._name)
{
    this->_mind = new Brain ();
    for (int i = 0; i < 100; i++)
        this->_mind->setIdea(src.getIdea(i), i);
    std::cout << "Cat ";
    if (this->_name != "")
        std::cout << this->_name;
    std::cout <<  "constructed from copy." << std::endl;
}

Cat::~Cat(void)
{
    delete this->_mind;
    std::cout << "Cat destroyed." << std::endl;
}

Cat  &Cat::operator=(Cat const &rhs)
{
    this->_type = rhs._type;
    this->_name = rhs._name;
    delete this->_mind;
    this->_mind = new Brain ();
    for (int i = 0; i < 100; i++)
        this->_mind->setIdea(rhs.getIdea(i), i);
    std::cout << "Cat copied." << std::endl;
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

std::string const   &Cat::getIdea(unsigned int index) const
{
    if (index >= 100)
    {
        std::cout << "Index too high ! Returning index [0]." << std::endl;
        return (this->_mind->getIdea(0));
    }
    return (this->_mind->getIdea(index));
}

void    Cat::setIdea(std::string newIdea, unsigned int index)
{
    if (index >= 100 || index < 0)
    {
        std::cout << "Index out of bounds, either too small or too high. Operation cancelled." << std::endl;
        return ;
    }
    this->_mind->setIdea(newIdea, index);
    return ;
}