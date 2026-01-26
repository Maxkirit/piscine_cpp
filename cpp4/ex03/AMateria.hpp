/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:09:54 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 17:35:37 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria(void);
        AMateria(AMateria const &src);
        AMateria(std::string const &type);
        AMateria    &operator=(AMateria const &rhs);
        virtual ~AMateria(void);

        std::string const   &getType(void) const; //Returns the materia type
        virtual AMateria*   clone(void) const = 0;
        virtual void        use(ICharacter &target) = 0;
};

#endif