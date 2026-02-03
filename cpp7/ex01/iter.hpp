/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:10:26 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/03 10:53:47 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <climits>
#include <cstdlib>

template<typename T>
void    iter(T const *array, size_t const size, void (&f)(T const &))
{
    //if f const in param, typecast in const do some test !!!
    for (size_t i = 0; i < size; i++)
        f(array[i]);
    return ;
}

template<typename T>
void    iter(T *array, size_t const size, void (&f)(T &))
{
    //if f const in param, typecast in const do some test !!!
    for (size_t i = 0; i < size; i++)
        f(array[i]);
    return ;
}

#endif