/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:10:58 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/19 19:09:36 by mturgeon         ###   ########.fr       */
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
		Fixed(int const n);
		Fixed(float const flt);
		Fixed(Fixed const &src);
		~Fixed(void);
		Fixed   &operator=(Fixed const &rhs);
		int     getRawBits(void) const;
		void    setRawBits(int const raw);
		float   toFloat(void) const;
		int     toInt(void) const;

	private:
		int                 _rawBits;
		static int const    _numFract = 8;
};

//important to pass fp as reference. Otherwise, copy is made in new stack,
//therefore constructor called and message printed.
std::ostream    &operator<<(std::ostream &o, Fixed const &fp);

#endif