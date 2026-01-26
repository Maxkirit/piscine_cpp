/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:01:53 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/26 13:55:11 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
    public:
        AAnimal(void);
        AAnimal(std::string type);
        AAnimal(AAnimal const &src);
        virtual ~AAnimal(void);
        AAnimal  &operator=(AAnimal const &rhs);

        std::string getType(void) const;
        
        virtual void    makeSound(void) const = 0;
    
    protected:
        std::string _type;
};

#endif