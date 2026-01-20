/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:56:51 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/20 12:58:07 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(Fixed const &x, Fixed const &y);
		Point(Point const &src);
		~Point(void);
		
		Point   &operator=(Point const &rhs);
		void    setX(Fixed const &newX);
		void    setY(Fixed const &newY);
		Fixed   getX(void) const;
		Fixed	getY(void) const;
	private:
		Fixed _x;
		Fixed _y;
};

#endif