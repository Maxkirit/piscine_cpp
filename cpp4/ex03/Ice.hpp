/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:14:07 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 14:46:00 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
    public:
        Ice(void);
        Ice(Ice const &src);
        virtual ~Ice(void);
        Ice &operator=(Ice const &rhs);

        virtual AMateria    *clone(void) const;
        virtual void        use(ICharacter &target);

};

#endif