/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:09:06 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 17:36:13 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void): _type(""){}

AMateria::AMateria(std::string const &type):
    _type(type)
{
    std::cout << this->_type << " materia created." << std::endl;
}

AMateria::AMateria(AMateria const &src):
    _type(src._type)
{
    std::cout << this->_type << " materia copied." << std::endl;
}
AMateria::~AMateria(void){}

std::string const   &AMateria::getType(void) const
{
    return (this->_type);
}

//pure virtual =0 --> the definition is NULL
// AMateria    *AMateria::clone(void) const{}

// All functions that are not pure virtual but are virtual must be defined.
// Therefore I set it to pure as well not to define it.
//void    AMateria::use(ICharacter &target)
// {}