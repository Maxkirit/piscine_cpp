/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:45:32 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/04 18:26:19 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <stack>

//by default, stack wraps a deque which has an iterator.
template<typename T>
class MutantStack: public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator  begin(void) { return (this->c.begin()); }
        iterator  end(void) { return (this->c.end()); }
};

#endif