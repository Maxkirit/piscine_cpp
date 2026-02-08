/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:29:02 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/08 20:09:47 by mturgeon         ###   ########.fr       */
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
		unsigned int				_jacobsthalNum(unsigned int n) const;

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
	T	start = next(iterator, -step + 1);
	T	end = next(start, step);

	//swap pairs until we get to old start.
	while (start != end)
	{
		std::swap(start, next(start, step));
		start++;
	}
}

//lists don't have random access iterators (vectors do) so pointer arithmetic won't work in this template.
template <typename T>
T	PmergeMe::_mergeInsertionSort(T &container)
{
	typedef typename T::iterator Iterator;

	static int	depth = 0;
	depth++;
	size_t		step = pow(2, depth - 1); //distance between first and last elem of any pair

	//end recursion when no swapping can be done
	if (step >= container.size() / 2)
		return (container);
	std::cout << "recursion depth: " << depth << std::endl;
	
	Iterator start = next(container.begin(), step - 1);
	Iterator last = next(container.end(), - (container.size() % step)); //last element included in pairs
	
	//"it" points to last elem of any subset.
	//can't use arithmetics so std::advance and no last member of for(...)
	for (Iterator it = start; it != last;)
	{
		Iterator nextIt = it;
		std::advance(nextIt, step);
		if (nextIt != container.end() && *it > *nextIt)
			_swapPairs(it, step);
		std::advance(it, step);
	}
	_mergeInsertionSort(container);

	//vectors that store the iterators at indexes of ai and bi.
	//b[0] === b1, a[0] === a1.
	std::vector<Iterator>	aIndex;
	std::vector<Iterator>	bIndex;
	int i = 0;
	for (Iterator it = start; it != last;)
	{
		Iterator nextIt = it;
		std::advance(nextIt, step);
		if (i % 2 == 0)
		{
			bIndex.push_back(it);
			if (nextIt <= last)
				aIndex.push_back(nextIt);
		}
		else
		{
			aIndex.push_back(it);
			bIndex.push_back(nextIt);
		}
		i++;
		std::advance(it, step);
	}
	
	unsigned int	n = 2;
	unsigned int	JacobDelta = _jacobsthalNum(n) - _jacobsthalNum(n - 1);

	//extra parentheses to prevent most vexing parse problem.
	return (T((start), (container.end())));
}

#endif