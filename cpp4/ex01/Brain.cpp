/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:42:18 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 11:35:09 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void):
    _idea("")
{
    // std::cout << "Empty brain constructed." << std::endl;
}

Brain::Brain(std::string idea):
    _idea(idea)
{
    // std::cout << "Brain containing \"" << this->_idea << "\" constructed." << std::endl;
}

Brain::Brain(Brain const &src):
    _idea(src._idea)
{
    // std::cout << "Brain copied with idea \"" << this->_idea << "\"." << std::endl;
}
Brain::~Brain(void)
{
    // std::cout << "Brain containing \"" << this->_idea << "\" destroyed." << std::endl;
}

std::string const &Brain::getIdea(void) const
{
    return (this->_idea);
}

void    Brain::setIdea(std::string newIdea)
{
    this->_idea = newIdea;
    return ;
}

