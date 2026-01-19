/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:11:59 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/19 19:14:34 by mturgeon         ###   ########.fr       */
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
Fixed::Fixed(int const n)
{
	this->_rawBits = n << this->_numFract;
	std::cout << "Int constructor called." << std::endl;
}

//roundf here to round to the nearest integer so we don't lose precision !
Fixed::Fixed(float const flt)
{
	this->_rawBits = roundf(flt * (1 << this->_numFract));
	std::cout << "Float constructor called." << std::endl;
}

int Fixed::toInt(void) const
{
	return (this->_rawBits >> this->_numFract);
}

float   Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << this->_numFract));
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

std::ostream	&operator<<(std::ostream &o, Fixed const &fp)
{
	o << fp.toFloat();
	return (o);
}