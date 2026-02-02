/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:37:18 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/02 20:47:36 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
    Array<int> a;
    int *b = new int();
    int *c = new int[0];

    try
    {
        std::cout << a[0] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << *b << std::endl;
    std::cout << c[0] << std::endl;
    return (0);

    // check if operator[] works with data types other than int (size_t, casted float, long long, etc)
}