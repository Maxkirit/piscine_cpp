/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:40:43 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/04 15:42:55 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

//span only contains unique elements
//span === distance between two elements
//if num of elem > size, insert impossible.
class Span
{
	private:
		unsigned int		_N;
		//using vector here is best since we want to access often but build only a few times in real world use.
		std::vector<int>	_vec;
		Span(void);

	public:
		Span(unsigned int size);
		Span(Span const &src);
		~Span(void);
		
		Span	&operator=(Span const &rhs);

		void				printArr(void) const;
		unsigned int		getSize(void) const;
		std::vector<int>	&getVec(void);
		//add functions sort _vec after each addition
		void 			addSequence(std::vector<int>::iterator begin, std::vector<int>::iterator end); //adds the range to the span
		void			addNumber(int num);
		
		//exception if no or one number stored
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
        class VecFull: public std::exception
        {
            public:
                virtual const char *what() const throw(){return ("no space left in vector");}
        };
        class NoSpan: public std::exception
        {
            public:
                virtual const char *what() const throw(){return ("vector has 1 or 0 elems: no span to return");}
        };
		
};

#endif