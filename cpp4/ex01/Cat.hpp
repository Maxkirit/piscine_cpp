/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:22:08 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 11:19:20 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    public:
        Cat(void);
        Cat(std::string name);
        Cat(Cat const &src);
        virtual ~Cat(void);

        Cat &operator=(Cat const &rhs);

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