/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:22:57 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 13:16:01 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void):
    Animal()
{
    this->_type = "Cat";
    this->_ideas = new Brain [_brainSize];
    for (int i = 0; i < _brainSize; i++)
        this->_ideas[i].setIdea("");
    std::cout << "Cat constructed." << std::endl;
}

Cat::Cat(std::string name):
    Animal(),
    _name(name)
{
    this->_type = "Cat";
    this->_ideas = new Brain [_brainSize];
    for (int i = 0; i < _brainSize; i++)
        this->_ideas[i].setIdea("");
    std::cout << "Cat named " << this->_name << " created." << std::endl;
}

Cat::Cat(Cat const &src):
    Animal(),
    _name(src._name)
{
    this->_type = "Cat";
    this->_ideas = new Brain [_brainSize];
    for (int i = 0; i < _brainSize; i++)
        this->_ideas[i].setIdea(src.getIdea(i));
    std::cout << "Cat ";
    if (this->_name != "")
        std::cout << this->_name;
    std::cout <<  "constructed from copy." << std::endl;
}

Cat::~Cat(void)
{
    delete [] this->_ideas;
    std::cout << "Cat destroyed." << std::endl;
}

Cat  &Cat::operator=(Cat const &rhs)
{
    this->_type = rhs._type;
    this->_name = rhs._name;
    this->_ideas = new Brain[_brainSize];
    for (int i = 0; i <_brainSize; i++)
        this->_ideas[i].setIdea(rhs.getIdea(i));
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

std::string const   &Cat::getIdea(int index) const
{
    if (index >= _brainSize)
    {
        std::cout << "Index too high ! Returning index [0]." << std::endl;
        return (this->_ideas[0].getIdea());
    }
    return (this->_ideas[index].getIdea());
}

void    Cat::setIdea(std::string newIdea, int index)
{
    if (index >= _brainSize || index < 0)
    {
        std::cout << "Index out of bounds, either too small or too high. Operation cancelled." << std::endl;
        return ;
    }
    this->_ideas[index].setIdea(newIdea);
    return ;
}