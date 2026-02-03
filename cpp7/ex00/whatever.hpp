/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:54:08 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/02 14:55:03 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void    swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
    return ;
}

template <typename T>
T const min(T const &a, T const &b)
{
    return (a < b ? (a) : (b));
}

template <typename T>
T const max(T const &a, T const &b)
{
    return (a > b ? (a) : (b));
}

#endif