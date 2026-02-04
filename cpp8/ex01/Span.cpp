/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:41:02 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/04 15:43:04 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int size): _N(size){}

Span::Span(Span const &src): 
	_N(src._N),
	_vec(std::vector<int>(src._vec.begin(), src._vec.end())){}

Span::~Span(void){}

Span	&Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_N = rhs._N;
		this->_vec.resize(this->_N);
		std::copy(rhs._vec.begin(), rhs._vec.end(), this->_vec.begin());
	}
	return (*this);
}

void	print(int num)
{
	std::cout << num << ", ";
	return ;
}

void	Span::printArr(void) const
{
	std::cout << "set: (";
	std::for_each(this->_vec.begin(), this->_vec.end() - 1, print);
	std::cout << this->_vec.back() << ")" << std::endl;
	return ;
}

void	Span::addNumber(int num)
{
    if (this->_vec.size() < this->_N)
    {
        this->_vec.push_back(num);
        std::sort(this->_vec.begin(), this->_vec.end());
        return ;
    }
    throw (Span::VecFull());
}

unsigned int	Span::getSize(void) const
{
	return (this->_N);
}

std::vector<int> &Span::getVec(void)
{
	return (this->_vec);
}

void	Span::addSequence(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{    
    size_t distance = std::distance(begin, end);
    if (distance + this->_vec.size() > this->_N)
        throw(Span::VecFull());
    this->_vec.insert(this->_vec.end(), begin, end);
    sort(this->_vec.begin(), this->_vec.end());
	return;
}

unsigned int	Span::shortestSpan(void) const
{
    if (this->_vec.size() < 2)
        throw(Span::NoSpan());
    int minDist = abs(this->_vec.at(1) - this->_vec.at(0));
    for (std::vector<int>::const_iterator it = this->_vec.begin(); it != this->_vec.end(); it++)
    {
        if (minDist > abs(*(it + 1) - *it))
            minDist = abs(*(it + 1) - *it);
    }
    return (minDist);
}
        
unsigned int	Span::longestSpan(void) const
{
    if (this->_vec.size() < 2)
        throw(Span::NoSpan());
    return (this->_vec.back() - this->_vec.front());
}