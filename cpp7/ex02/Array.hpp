/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 18:28:33 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/03 10:29:20 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>

template<typename T = int>
class Array
{
    private:
        size_t  _size;
        T       *_array;

    public:
        Array(void);
        Array(unsigned int const &n);
        Array(Array const &src);
        ~Array(void);

        Array   &operator=(Array const &rhs);
        T       &operator[](size_t i);
        size_t const    &size(void) const;
        void    setValueAtIndex(T const &val, size_t const &i);
};

//The make compiler happy about template declaration outside of header.
//Can't be above class def.
//Other options involve doing explicit instanciations in the .tpp file.
//This would lock the types usable with the template, which is counterproductive.
#include "Array.tpp"

#endif