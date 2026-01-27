/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:42:18 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 11:20:51 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    for (int i = 0; i < 100; i++)
        _idea[i] = "";
    // std::cout << "Empty brain constructed." << std::endl;
}

Brain::Brain(Brain const &src)
{
    for (int i = 0; i < 100; i++)
        _idea[i] = src._idea[i];
    // std::cout << "Brain copied with idea \"" << this->_idea << "\"." << std::endl;
}
Brain::~Brain(void)
{
    // std::cout << "Brain containing \"" << this->_idea << "\" destroyed." << std::endl;
}

std::string const &Brain::getIdea(unsigned int idx) const
{
    return (this->_idea[idx]);
}

void    Brain::setIdea(std::string newIdea, unsigned int idx)
{
    this->_idea[idx] = newIdea;
    return ;
}

