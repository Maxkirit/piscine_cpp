/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:23:09 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 11:19:21 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
    public:
        Dog(void);
        Dog(std::string name);
        Dog(Dog const &src);
        virtual ~Dog(void);

        Dog &operator=(Dog const &rhs);

        std::string         getName(void) const;
        std::string         getType(void) const;
        std::string const   &getIdea(unsigned int index) const;
        void                setIdea(std::string newIdea, unsigned int index);

        virtual void    makeSound(void) const;
    private:
        std::string _name;
        Brain       *_mind;
};

#endif