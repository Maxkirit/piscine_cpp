/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:19:14 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 14:53:14 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
    public:
        Cure(void);
        Cure(Cure const &src);
        virtual ~Cure(void);
        Cure &operator=(Cure const &rhs);

        virtual AMateria    *clone(void) const;
        virtual void        use(ICharacter &target);

};

#endif