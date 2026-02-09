/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:29:02 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/09 20:44:39 by mturgeon         ###   ########.fr       */
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
#include <fstream>
#include <string>

class PmergeMe
{
	private:
		PmergeMe(void);
		std::string					_sequence;
		std::vector<unsigned int>	_vecSorted;
		std::list<unsigned int>		_listSorted;

		template<typename T> void		_mergeInsertionSort(T &container, size_t elemSize);
		template<typename T> void	_swapPairs(T &iterator, int step);
		std::vector<unsigned int>	_strToVec(void) const;
		std::list<unsigned int>		_strToList(void) const;
		unsigned int			_jacobsthalNum(unsigned int n) const;

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

//min depth == 1.
//we do pairs of 2*depth elements
//T is iterator to container type centered on term to swap
template<typename T> void	PmergeMe::_swapPairs(T &iterator, int step)
{
	T	start = iterator;
	std::advance(start, -step + 1);
	T	end = start;
	std::advance(end, step);

	//swap pairs until we get to old start.
	while (start != end)
	{
		T	temp = start;
		std::advance(temp, step);
		std::swap(*start, *temp);
		start++;
	}
}

//lists don't have random access iterators (vectors do) so pointer arithmetic won't work in this template.
template <typename T>
void PmergeMe::_mergeInsertionSort(T &container, size_t elemSize)
{
    typedef typename T::iterator Iterator; 

    size_t  totalElems = container.size() / elemSize;
    if (totalElems < 2)
        return ;

    size_t pairNum = totalElems / 2;

    //swap recursively bigger pairs
    for (size_t i = 0; i < pairNum; i++)
    {
        Iterator    first = container.begin();
        std::advance(first, i * 2 * elemSize + elemSize - 1); 
        Iterator    second = first;
        std::advance(second, elemSize); 
        
        if (*first > *second)
            _swapPairs(first, elemSize);
    }
    _mergeInsertionSort(container, 2 * elemSize);

    std::vector<Iterator>   main;
    std::vector<Iterator>   pend;
    Iterator                it = container.begin(); 
    Iterator                b1 = it; std::advance(b1, elemSize - 1);
    Iterator                a1 = b1; std::advance(a1, elemSize);
    main.push_back(b1); //main always have at least b1 a1
    main.push_back(a1);
    std::advance(it, 2 * elemSize);

    //fill 
    for (size_t i = 1; i < pairNum; ++i) 
    {
        Iterator bi = it;
        std::advance(bi, elemSize - 1);
        Iterator ai = bi;
        std::advance(ai, elemSize);
        
        pend.push_back(bi); //put all remaining bi in pend
        main.push_back(ai); //put all remaining ai in main
        std::advance(it, 2 * elemSize);
    }
    
    //all the leftovers that might not be part of a pair
    Iterator    oddBlock = container.end();
    int hasOdd = 0;
    if (totalElems % 2 != 0)
        hasOdd = 1;
    if (hasOdd)
    {
        oddBlock = it;
        std::advance(oddBlock, elemSize - 1);
        pend.push_back(oddBlock);
    }

    size_t  insertedCount = 0;
    size_t  jacobIndex = 3; // Start from J(3) 
    while (insertedCount < pend.size()) //stop when you have inserted all the numbers
    {
        size_t  currJacob = _jacobsthalNum(jacobIndex);
        size_t  prevJacob = _jacobsthalNum(jacobIndex - 1);    
        size_t  groupLen = currJacob - prevJacob; //number of bi in range 
        
        //insert elements from pend in reverse order
        //start either from Jacob sequence or the end
        for (size_t i = groupLen; i > 0; --i)
        {
            size_t pendIdx = prevJacob + i - 2;
            //we never empty pending therefore we will overshoot the buffer eventually
            //if we do, just iterate and go in reverse order from the end since we're past it
            if (pendIdx >= pend.size())
                continue;

            Iterator    toInsert = pend[pendIdx];
            
            //find the upper bound to insert.
            //if we have to insert oddBlock, upper bound is the end ==> extreme case where we search the whole sequence
            //else, we won't search beyond pendIdx + 2 + insertedCount  as this is the ak to our bk => the upper bound
            typename std::vector<Iterator>::iterator    searchLimit;
            if (hasOdd && toInsert == oddBlock)
                searchLimit = main.end();
            else
            {
                size_t  limitIdx = pendIdx + 2 + insertedCount;
                if (limitIdx > main.size())
                    limitIdx = main.size();
                searchLimit = main.begin();
                std::advance(searchLimit, limitIdx);
            }

            //function does the search for us
            typename std::vector<Iterator>::iterator    idx = std::upper_bound(main.begin(), searchLimit, toInsert, _comp<Iterator>);
            main.insert(idx, toInsert);
            insertedCount++;
        }
        jacobIndex++;
    }
    
    //rebuild result from the iterators.
    typename std::vector<int>   ret;
    ret.reserve(container.size());
    for (typename std::vector<Iterator>::iterator   it = main.begin(); it != main.end(); ++it)
    {
        Iterator    blockEndIt = *it;
        Iterator    blockStart = blockEndIt;
        std::advance(blockStart, -(static_cast<long>(elemSize) - 1));
        for (size_t i = 0; i < elemSize; i++)
        {
            ret.push_back(*blockStart);
            std::advance(blockStart, 1);
        }
    }

    std::copy(ret.begin(), ret.end(), container.begin());
}

#endif