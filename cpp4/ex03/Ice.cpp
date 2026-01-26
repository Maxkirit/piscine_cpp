/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:19:01 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 15:00:08 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice"){}

Ice::Ice(Ice const &src): AMateria(){
    this->_type = src._type;
}

Ice::~Ice(void){}

void    Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria    *Ice::clone(void) const
{
    std::cout << "Ice materia cloned." << std::endl;
    return (new Ice());
}