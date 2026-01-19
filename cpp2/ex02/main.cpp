/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:10:38 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/19 21:05:03 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

    Fixed       a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed       c(1.5f);
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << "my tests: " << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << a/b << std::endl;
    std::cout << b/b << std::endl;
    std::cout << b/c << std::endl;
    std::cout << Fixed::min(a-b, a+b) << std::endl;
    std::cout << Fixed::max(c/b, b/c) << std::endl;
    std::cout << Fixed::min(c/b, b/c) << std::endl;
    std::cout << b + c << std::endl;
    std::cout << b - c << std::endl;
    return 0;
}