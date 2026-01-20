/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:57:43 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/20 12:58:45 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void):
	_x(),
	_y()
{
	std::cout << "Default point constructor called." << std::endl;
}

Point::Point(Fixed const &x, Fixed const &y):
	_x(x),
	_y(y)
{
	std::cout << "Constructor called for point (" << _x.toFloat() << ", " << _y.toFloat() << ")." << std::endl;
}

Point::Point(Point const &src):
	_x(src._x),
	_y(src._y)
{
	std::cout << "Copy constructor called for point (" << _x.toFloat() << ", " << _y.toFloat() << ")." << std::endl;
}

Point::~Point(void)
{
	std::cout << "Default destructor called for point (" << _x.toFloat() << ", " << _y.toFloat() << ")." << std::endl;
}

Point   &Point::operator=(Point const &rhs)
{
	this->setX(rhs._x);
	this->_y = rhs._y;
	return (*this);
}

void    Point::setX(Fixed const &newX)
{
	this->_x.setRawBits(newX.getRawBits());
	return ; 
}

void	Point::setY(Fixed const &newY)
{
	this->_y.setRawBits(newY.getRawBits());
	return ;
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed   Point::getY(void) const
{
    return (this->_y);
}