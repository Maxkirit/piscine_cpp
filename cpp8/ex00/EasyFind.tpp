/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:33:56 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/04 10:34:38 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"

template<typename Container >
int	&easyfind(Container &cont, int const val)
{
    typename Container::iterator it; //typename here informs the compiler that Container is a type here and not an object
    
    it = find(cont.begin(), cont.end(), val);
    if (it == cont.end())
        throw(std::invalid_argument("value not found")); // apparently "non trivial performance overhead" 
    return (*it);
}