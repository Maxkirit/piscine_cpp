/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 08:58:06 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/04 10:36:56 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"

int main(void)
{
    int arr[] = {11, 23, 45 , 89, -100};
    std::vector<int>    v1;
    std::vector<int>    v2(arr, arr + 5);
    std::vector<int>    v3(5, 11);
    std::vector<int>    v4(v2.begin(), v2.end());
    std::vector<int>    v5;
    std::list<int>      l1(arr, arr +5);
    std::list<int>      l2;
    std::list<int>      l3(5, 11);
    std::list<int>      l4 = l1;
    std::list<int>      l5(v2.begin(), v2.end());
    std::deque<int>     d1(arr, arr + 5);

    //empty
    std::vector<int>    ve;
    std::list<int>      le;
    std::deque<int>     de;

    v1.push_back(11);
    v1.push_back(23);
    v1.push_back(45);
    v1.push_back(89);
    v1.push_back(-100);
    fill(v5.begin(), v5.end(), 11);

    l2.push_back(11);
    l2.push_back(23);
    l2.push_back(45);
    l2.push_back(89);
    l2.push_back(-100);
    
    std::cout << "~~~VECTORS~~~" << std::endl;
    try
    {
        std::cout << easyfind(v1, 89) << std::endl;
        std::cout << easyfind(v2, 89) << std::endl;
        std::cout << easyfind(v4, 89) << std::endl;
        std::cout << easyfind(v2, 89) << std::endl;
        std::cout << easyfind(v5, 89) << std::endl;
    }
    catch(std::exception const &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "~~~SET AND LISTS~~~" << std::endl;
    try
    {
        std::cout << easyfind(l1, 89) << std::endl;
        std::cout << easyfind(l4, 89) << std::endl;
        std::cout << easyfind(l5, 89) << std::endl;
        std::cout << easyfind(l3, 89) << std::endl;
        std::cout << easyfind(l2, 89) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "~~~DEQUE~~~" << std::endl;
    try
    {
        std::cout << easyfind(d1, 89) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "~~~NON INITIALIZED CONTAINERS~~~" << std::endl;
    try
    {
        std::cout << easyfind(ve, 89) << std::endl;
        std::cout << easyfind(le, 89) << std::endl;
        std::cout << easyfind(de, 89) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}