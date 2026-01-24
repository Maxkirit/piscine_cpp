/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:23:09 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/24 17:37:44 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog(void);
        Dog(std::string name);
        Dog(Dog const &src);
        ~Dog(void);

        Dog &operator=(Dog const &rhs);

        std::string getName(void) const;
        std::string getType(void) const;

        virtual void    makeSound(void) const;
    private:
        std::string _name;
};


#endif