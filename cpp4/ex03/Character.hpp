/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:00:35 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 18:32:13 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character: public ICharacter
{
    private:
        std::string     _name;
        AMateria        *_inventory[4];
        unsigned int    _equipCount;
        AMateria        *_discard[1024];
        unsigned int    _discardCount;

    public:
        Character(void);
        Character(Character const &src);
        Character(std::string name);
        Character   &operator=(Character const &rhs);
        virtual ~Character(void);

        virtual std::string const &getName(void) const;
        virtual void    equip(AMateria *m);
        virtual void    unequip(int idx);
        virtual void    use(int idx, ICharacter& target);
        bool            inInventory(AMateria *m) const;
};

#endif