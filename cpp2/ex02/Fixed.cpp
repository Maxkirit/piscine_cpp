/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:11:59 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/19 21:05:46 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void):
	_rawBits(0)
{
	// std::cout << "Default constructor called." << std::endl;
}
Fixed::~Fixed(void)
{
	// std::cout << "Destructor called." << std::endl;
}
Fixed::Fixed(int const n)
{
	if (n < 0)
	{
		std::cout << "No neg values please." << std::endl;
		return ;
	}
	this->_rawBits = n << this->_numFract;
	// std::cout << "Int constructor called." << std::endl;
}

//roundf here to round to the nearest integer so we don't lose precision !
Fixed::Fixed(float const flt)
{
	if (flt < 0)
	{
		std::cout << "No neg values please." << std::endl;
		return ;
	}
	this->_rawBits = roundf(flt * (1 << this->_numFract));
	// std::cout << "Float constructor called." << std::endl;
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
	// std::cout << "Copy constructor called." << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	this->_rawBits = rhs._rawBits;
	// std::cout << "Copy assignement operator called." << std::endl;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called." << std::endl;
	return (this->_rawBits);
}

//does this work natively with neg numbers ??
void	Fixed::setRawBits(int const raw)
{	
	if (raw < 0)
	{
		std::cout << "No neg values please." << std::endl;
		return ;
	}	
	// std::cout << "setRawBits member function called." << std::endl;
	this->_rawBits = raw;
	return ;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &fp)
{
	o << fp.toFloat();
	return (o);
}

//const required here bc otherwise cant be called with const as left operand !
Fixed   Fixed::operator+(Fixed const &rhs) const
{
	Fixed	temp;
	temp._rawBits = this->_rawBits + rhs._rawBits;
	return (temp);
}

Fixed   Fixed::operator-(Fixed const &rhs) const
{
	Fixed	temp;
	temp._rawBits = this->_rawBits - rhs._rawBits;
	return (temp);
}

//to prevent oveflow, we typecast to a 64bit type first
Fixed   Fixed::operator*(Fixed const &rhs) const
{
	Fixed	res;

	long long temp = static_cast<long long>(this->_rawBits) * rhs._rawBits;
	res.setRawBits(static_cast<int>(temp >> _numFract));
	return (res);
}

Fixed   Fixed::operator/(Fixed const &rhs) const
{
	Fixed res;
	
    long long temp = static_cast<long long>(this->_rawBits) << _numFract;
    res.setRawBits(static_cast<int>(temp / rhs._rawBits));
	return (res);
}

bool    Fixed::operator==(Fixed const &rhs)
{
	int delta = this->_rawBits - rhs._rawBits;
	delta = abs(delta);
	return (bool)delta;
}

bool    Fixed::operator!=(Fixed const &rhs)
{
	if (this->_rawBits != rhs._rawBits)
		return (1);
	return (0);
}

bool	Fixed::operator>(Fixed const &rhs)
{
	if (this->_rawBits > rhs._rawBits)
		return (1);
	return (0);
}
bool	Fixed::operator<(Fixed const &rhs)
{
	if (this->_rawBits < rhs._rawBits)
		return (1);
	return (0);
}

bool	Fixed::operator>=(Fixed const &rhs)
{
	if (this->_rawBits >= rhs._rawBits)
		return (1);
	return (0);
}

bool	Fixed::operator<=(Fixed const &rhs)
{
	if (this->_rawBits <= rhs._rawBits)
		return (1);
	return (0);
}

Fixed	&Fixed::operator++(void)
{
	this->_rawBits++;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->_rawBits--;
	return (*this);
}

//use prefix operator as post fix is overloaded!
Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	++(*this);
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	--(*this);
	return (temp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a._rawBits < b._rawBits)
		return (a);
	return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a._rawBits > b._rawBits)
		return (a);
	return (b);
}