/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 10:56:51 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/20 11:05:35 by mturgeon         ###   ########.fr       */
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
    private:
        Fixed const x;
        Fixed const y;
};

#endif