/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:06:14 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 18:51:35 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    private:
        AMateria        *_slots[4];
        unsigned int    _materiaNum;

    public:
        MateriaSource(void);
        MateriaSource(MateriaSource const &src);
        virtual ~MateriaSource(void);

        MateriaSource   &operator=(MateriaSource const &rhs);

        virtual void        learnMateria(AMateria *m);
        virtual AMateria    *createMateria(std::string const &type); //returns a materia only if materia of type in slots
        bool                inSlots(AMateria *m) const;
    };

#endif