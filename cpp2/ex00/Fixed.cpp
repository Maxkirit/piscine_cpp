/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:11:59 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/19 18:25:02 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void):
	_rawBits(0)
{
	std::cout << "Default constructor called." << std::endl;
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called." << std::endl;
}

Fixed::Fixed(Fixed const &src):
	_rawBits(src._rawBits)
{
	std::cout << "Copy constructor called." << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	this->_rawBits = rhs._rawBits;
	std::cout << "Copy assignement operator called." << std::endl;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called." << std::endl;
	return (this->_rawBits);
}

//does this work natively with neg numbers ??
void	Fixed::setRawBits(int const raw)
{		
    std::cout << "setRawBits member function called." << std::endl;
	this->_rawBits = raw;
	return ;
}