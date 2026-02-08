/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:34:40 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/08 20:08:00 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string &input): _sequence(input), _vecSorted(0), _listSorted(0){}

PmergeMe::PmergeMe(PmergeMe const &src){*this = src;}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		this->_sequence = rhs._sequence;
		this->_vecSorted = rhs._vecSorted;
		this->_listSorted = rhs._listSorted;
	}
	return (*this);
}

std::vector<unsigned int> const	&PmergeMe::getVecSorted(void) const {return (this->_vecSorted);}

std::list<unsigned int> const	&PmergeMe::getListSorted(void) const{return (this->_listSorted);}

double	PmergeMe::sortVec(void)
{
	timeval	start;
	timeval	finish;
	std::vector<unsigned int>	sequence = this->_strToVec();

	gettimeofday(&start, 0);
	this->_vecSorted = _mergeInsertionSort(sequence);
	gettimeofday(&finish, 0);
	return (finish.tv_usec - start.tv_usec);
}

double	PmergeMe::sortList(void)
{
	timeval	start;
	timeval	finish;
	std::list<unsigned int>	sequence = this->_strToList();

	gettimeofday(&start, 0);
	this->_listSorted = _mergeInsertionSort(sequence);
	gettimeofday(&finish, 0);
	return (finish.tv_usec - start.tv_usec);
}

std::vector<unsigned int>	PmergeMe::_strToVec(void) const
{
	std::stringstream	data(this->_sequence);
	return (std::vector<unsigned int>(std::istream_iterator<unsigned int>(data), std::istream_iterator<unsigned int>()));
}

std::list<unsigned int>		PmergeMe::_strToList(void) const
{
	std::stringstream			data(this->_sequence);
	return (std::list<unsigned int>(std::istream_iterator<unsigned int>(data), std::istream_iterator<unsigned int>()));
}

//return Jacobsthal sequence number 
//upper bound to limit cases that over
unsigned int	PmergeMe::_jacobsthalNum(unsigned int n) const
{
	if (n > 33)
		throw(std::runtime_error("Jacobsthal number overflow!"));
	return ((pow(2, n) - pow(-1, n)) / 3);
}