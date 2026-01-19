/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:10:58 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/19 18:09:21 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

#define EPSILON 1.0e-7 
#define float_equals(a, b) (fabs((a)-(b)) < EPSILON)

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);
		Fixed   &operator=(Fixed const &rhs);
		int     getRawBits(void) const;
		void    setRawBits(int const raw);
	private:
		int                 _rawBits;
		static int const    _numFract = 8;
};

#endif