/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:20:10 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 14:53:05 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure"){}

Cure::Cure(Cure const &src): AMateria(){
    this->_type = src._type;
}

Cure::~Cure(void){}

void    Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria    *Cure::clone(void) const
{
    std::cout << "Cure materia cloned." << std::endl;
    return (new Cure());
}