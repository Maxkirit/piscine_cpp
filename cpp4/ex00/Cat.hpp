/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:22:08 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/24 17:37:08 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat(void);
        Cat(std::string name);
        Cat(Cat const &src);
        ~Cat(void);

        Cat &operator=(Cat const &rhs);

        std::string getName(void) const;
        std::string getType(void) const;

        virtual void    makeSound(void) const;
    private:
        std::string _name;
};

#endif