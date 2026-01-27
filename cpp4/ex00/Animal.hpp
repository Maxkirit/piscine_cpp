/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:01:53 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 11:00:51 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    public:
        Animal(void);
        Animal(Animal const &src);
        virtual ~Animal(void);

        Animal  &operator=(Animal const &rhs);

        std::string getType(void) const;
        
        virtual void    makeSound(void) const;
    
    protected:
        std::string _type;
};

#endif