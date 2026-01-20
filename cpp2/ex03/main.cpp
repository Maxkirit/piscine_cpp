/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:10:38 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/20 18:07:41 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Fixed	computeArea2(Point const &a, Point const &b, Point const &c)
{
	return (c.getY()*b.getX() - b.getY()*c.getX()
			+ a.getY()*(c.getX() - b.getX())
			+ a.getX()*(b.getY() - c.getY()));
}

//a, b, c are the vertices ("sommets" in French) of the triangle
//returns 1 if STRICTLY inside a triangle
//a, b, c nodes that are COUNTERCLOCK WISE !!!
bool	intersectsTriangle(Point const a, Point const b, Point const c, Point const p)
{
	Fixed	Area2(Fixed(computeArea2(a, b, c)));

	std::cout << "before s" << std::endl;
	Fixed   s(Fixed((1.0f / (Area2.toFloat())))
				* (a.getY()*c.getX() - a.getX()*c.getY()
				+ p.getX()*(c.getY() - a.getY())
				+ p.getY()*(a.getX() - c.getX())));
	std::cout << "before t" << std::endl;
	Fixed	t(Fixed((1.0f / (Area2.toFloat())))
				* (a.getX()*b.getY() - a.getY()*b.getX()
				+ p.getX()*(a.getY() - b.getY())
				+ p.getY()*(b.getX() - a.getX())));
	
	if (s > 0 && t > 0 && Fixed(1) - s - t > 0)
		return true;
	return false;
}

//vertices: "sommets" of the triangles.
int main(void) {

	Point	a(Fixed(1.0f), Fixed(3.0f));
	Point	b(Fixed(18.0f), Fixed(0.0f));
	Point	c(Fixed(5.0f), Fixed(13.0f));
	Point	p(Fixed(5.0f), Fixed(26.0f));

	if (intersectsTriangle(a, b, c, p))
		std::cout << "IT'S A HIT !!!" << std::endl;
	else
		std::cout <<"IT'S A MISS..." << std::endl;
	return (0);
}