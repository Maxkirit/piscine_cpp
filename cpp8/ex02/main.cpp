/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:46:53 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/04 18:51:11 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	randomNum(void)
{
	return (std::rand()%10000); //returns random values between 0 and 10000
}

int main(void)
{
    std::srand(time(0));
    {
        std::cout << "~~~~~~SUBJECT TESTS ~~~~~~" << std::endl;
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        std::cout << mstack.size() << std::endl;
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << "stack content: " << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        std::cout << "~~~~~~OTHER TESTS ~~~~~~" << std::endl;
        std::cout << "LIST: " << std::endl;
        std::list<int> comp(10);
        generate(comp.begin(), comp.end(), randomNum);
        for (std::list<int>::iterator it = comp.begin(); it != comp.end(); it++)
            std::cout << *it << std::endl;
        comp.pop_back();
        comp.push_back(999999);
        std::cout << "after pop back and push_back:" << std::endl;
        for (std::list<int>::iterator it = comp.begin(); it != comp.end(); it++)
            std::cout << *it << std::endl;
        
        std::cout << "MUTANT STACK: " << std::endl;
        MutantStack<int> test;
        test.push(0);
        test.push(10);
        test.push(20);
        test.push(30);
        test.push(40);

        MutantStack<int>::iterator it = test.begin();
        MutantStack<int>::iterator ite = test.end();
        
        std::cout << "test mutant stack after our own init: " << std::endl;
        for (MutantStack<int>::iterator it = test.begin(); it != test.end(); it++)
            std::cout << *it << std::endl;
        generate(it, ite, randomNum);
        std::cout << "test mutant stack after random num: " << std::endl;
        for (MutantStack<int>::iterator it = test.begin(); it != test.end(); it++)
            std::cout << *it << std::endl;

        test.pop();
        test.pop();
        test.push(-1);
        test.push(-1);
        std::cout << "test mutant stack after pop/push: " << std::endl;
        for (MutantStack<int>::iterator it = test.begin(); it != test.end(); it++)
            std::cout << *it << std::endl;
    }
    return (0);
}