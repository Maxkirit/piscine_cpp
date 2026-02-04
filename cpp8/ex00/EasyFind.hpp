/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:05:55 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/04 10:36:10 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <deque>
#include <set>


template<typename Container >
int	&easyfind(Container &cont, int const val);

#include "EasyFind.tpp"

#endif