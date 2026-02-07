/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:29:02 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/07 17:44:22 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <list>
#include <sys/time.h> //on linux

class PmergeMe
{
	private:
		PmergeMe(void);
		std::string					_sequence;
		std::vector<unsigned int>	_vecSorted;
		std::list<unsigned int>		_listSorted;

		template<typename T> T		_mergeInsertionSort(T &container);
		template<typename T> void	_swapPairs(T &container, int step);
		std::vector<unsigned int>	_strToVec(void) const;
		std::list<unsigned int>		_strToList(void) const;

	public: 
		PmergeMe(std::string &input);
		PmergeMe(PmergeMe const &src);
		PmergeMe	&operator=(PmergeMe const &rhs);
		std::vector<unsigned int> const	&getVecSorted(void) const;
		std::list<unsigned int> const	&getListSorted(void) const;

		//return delta time for sorting operations
		//get time before calling mergeInsertionSort for timing delay
		double	sortVec(void);
		double	sortList(void);		
};


//min depth == 1.
//we do pairs of 2*depth elements
//T is iterator to container type centered on term to swap
template<typename T> void	_swapPairs(T &iterator, int step)
{
	T	start = next(iterator, step + 1);
	T	end = next(start, step);

	//swap pairs until we get to old start.
	while (start != end)
	{
		std::iter_swap(start, next(start, step));
		start++;
	}
}

template <typename T>
T	PmergeMe::_mergeInsertionSort(T &container)
{
	typedef typename T::iterator Iterator;

	static int	depth = 0;
	depth++;
	int			step = 2 * depth - 1; //distance between first and last elem of any pair
	int			elemSize = step + 1;

	Iterator start = container.begin();
	Iterator last = next(container.end(), - (container.size() % elemSize)); //last element included in pairs
	
	for (Iterator it = start; it != last; next(it, step))
	{
		if (*it > *(it + step))
			_swapPairs(it, step)
	}
	_mergeInsertionSort(container);
	return (T(start, container.end()));

}

#endif