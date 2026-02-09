/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:29:02 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/09 15:46:14 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>
#include <sys/time.h>
#include <cmath>
#include <limits>

class PmergeMe
{
	private:
		PmergeMe(void);
		std::string					_sequence;
		std::vector<unsigned int>	_vecSorted;
		std::list<unsigned int>		_listSorted;

		template<typename T> T		_mergeInsertionSort(T &container);
		template<typename T> void	_swapPairs(T &iterator, int step);
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

//small function to make upper_bound happy
template<typename T> bool	_comp(T a, T b)
{
    return (*a < *b);
}

//lists don't have random access iterators (vectors do) so pointer arithmetic won't work in this template.
template <typename T>
T	PmergeMe::_mergeInsertionSort(T &container)
{
	typedef typename T::iterator Iterator;

	static int	depth = 0;
	depth++;
	size_t		elemSize = std::pow(2, depth - 1); //pairs are 2 * elemSize wide
	size_t		pairNum = container.size() / (2 * elemSize);
	

	if (pairNum <  2)
		return (container);

	for (size_t i = 0; i < pairNum; i++)
	{
		Iterator first = container.begin();
		std::advance(first, i * 2 * elemSize + elemSize - 1); 
		Iterator second = first;
		std::advance(second, elemSize); 
		if (*first > *second)
			_swapPairs(first, elemSize);
	}	
	_mergeInsertionSort(container);

	//main and pending iterator vecs. Do the insertion on them then copy everything into a new container at the end
	std::vector<Iterator>   main;
	std::vector<Iterator>   pend;

	//initialize main and pending chains
	Iterator    start = container.begin();
	Iterator    first = start;
	std::advance(first, 2 * elemSize - 1);
	Iterator    second = first;
	std::advance(second, 2 * elemSize);

	main.insert(main.end(), first);
	main.insert(main.end(), second);

	//i * elemSize points to ai when i == 5, hence "inverse logic" compared to swap
	for (size_t i = 4; i <= pairNum; i +=2)
	{
		Iterator    mainI = start;
		std::advance(mainI, i * (elemSize + 1) - 1);
		Iterator    pendI = start;
		std::advance(pendI, (i - 1) * (elemSize + 1) - 1);
		
		main.insert(main.end(), mainI);
		pend.insert(pend.end(), pendI);
	}
	//add last pair to pending when pairNum odd
	if (pairNum % 2 == 1)
	{
		Iterator    last = start;
		std::advance(last, (elemSize + 1) * (pairNum - 1));
		std::advance(last, elemSize);
		pend.insert(pend.end(), last);
	}

	
	unsigned int	n = 3; //J(3) == 3
	unsigned int    jacobNum = _jacobsthalNum(n);
	unsigned int	jacobDelta = jacobNum - _jacobsthalNum(n - 1);
	int				insertIndex = jacobDelta - 1;
	int				insertedNum = 0;

	while (jacobDelta > pend.size())
	{
		while (insertIndex >= 0)
		{
			typename std::vector<Iterator>::iterator mainIt = main.begin();
			std::advance(mainIt, insertedNum + jacobNum); //index of matching upper bound
			typename std::vector<Iterator>::iterator pendIt = pend.begin();
			std::advance(pendIt, insertIndex);

			main.insert(std::upper_bound(main.begin(), mainIt, *pendIt, _comp<Iterator>), *pendIt);
			pend.erase(pendIt);
			insertIndex--;
			insertedNum++;
		}
		jacobDelta--;
		if (jacobDelta == 0)
		{
			n++;
			jacobDelta = _jacobsthalNum(n) - _jacobsthalNum(n - 1);
			insertIndex = jacobDelta - 1;
		}
	}
	//when number of pending left is smaller than next jacob diff, got at it in reverse order
	for (int i = pend.size() - 1; i >=0; i--)
	{
		typename std::vector<Iterator>::iterator mainIt = main.begin();
		std::advance(mainIt, main.size() - pend.size() + i);
		if (pairNum % 2 == 1)
			std::advance(mainIt, i);
		typename std::vector<Iterator>::iterator pendIt = pend.begin();
		std::advance(pendIt, i);

		main.insert(std::upper_bound(main.begin(), mainIt, *pendIt, _comp<Iterator>), *pendIt);
		pend.erase(pendIt);
	}

	//create intermediate vect with result of this level
	std::vector<int> ret;
	ret.reserve(container.size());
	for (typename std::vector<Iterator>::iterator it = main.begin(); it != main.end(); it++)
	{
		for (unsigned long i = 0; i < elemSize - 1; i++)
        {
            Iterator pairStart = *it;
            std::advance(pairStart, -elemSize + i);
            ret.insert(ret.end(), *pairStart);
        }
	}

	//overwrite values in orignal container
	Iterator containerIt = container.begin();
    std::vector<int>::iterator retIt = ret.begin();
    while (retIt != ret.end())
    {
        *containerIt = *retIt;
        std::advance(containerIt, 1);
        retIt++;
    }
	return (container);
}


//min depth == 1.
//we do pairs of 2*depth elements
//T is iterator to container type centered on term to swap
template<typename T> void	PmergeMe::_swapPairs(T &iterator, int step)
{
	T	start = iterator;
	std::advance(start, -step + 1);
	T	end = start;
	std::advance(end, step);

	std::cout << "in swap pair" << std::endl;
	//swap pairs until we get to old start.
	while (start != end)
	{
		T	temp = start;
		std::advance(temp, step);
		std::swap(*start, *temp);
		start++;
	}
}



#endif