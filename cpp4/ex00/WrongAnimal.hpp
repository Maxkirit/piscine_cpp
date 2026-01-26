/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 09:10:23 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 10:29:57 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    public:
        WrongAnimal(void);
        WrongAnimal(WrongAnimal const &src);
        ~WrongAnimal(void);

        WrongAnimal &operator=(WrongAnimal const &rhs);
        
        std::string     getName(void) const;
        void            setName(std::string name);
        std::string     getType(void) const;
        virtual void    makeSound(void) const;
    protected:
        std::string _type;
        std::string _name;
};

#endif