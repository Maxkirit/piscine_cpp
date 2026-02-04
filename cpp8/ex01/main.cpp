/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:40:28 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/04 15:43:50 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	randomNum(void)
{
	return (std::rand()%10000); //returns random values between 0 and 10000
}

int main(void)
{
    {	

        std::cout << "~~~~~~~ FIRST TEST ~~~~~~~" << std::endl;
        Span s1(100);
        Span s2(5);
        
        std::srand(time(0));
        try
        {
            for (unsigned int i = 0; i < 10; i++)
            {
                if (i % 2 == 0)
                    s1.addNumber(-1 * i);
                else
                    s1.addNumber(i);
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
                
        std::vector<int> temp(5);
        std::generate(temp.begin(), temp.end(), randomNum);
        s2.addSequence(temp.begin(), temp.end());
        std::cout << "s2 content:" << std::endl;
        s2.printArr();
        
        std::cout << "s1 after merge: " << std::endl;
        s1.addSequence(s2.getVec().begin(), s2.getVec().end());
        s1.printArr();
        
        try
        {
            std::cout << "s1 shortest span: " << s1.shortestSpan() << std::endl;
            std::cout << "s1 longest span: " << s1.longestSpan() << std::endl;
            std::cout << "s2 shortest span: " << s2.shortestSpan() << std::endl;
            std::cout << "s2 longest span: " << s2.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        std::cout << "~~~~~~~ ERROR TESTS ~~~~~~~" << std::endl;
        Span s1(0);
        Span s2(1);
        Span s3(5);
        
        s2.addNumber(5);

        s3.addNumber(-45);
        s3.addNumber(-989861);
        s3.addNumber(56874);
        s3.addNumber(58);
        s3.addNumber(42);
        
        try
        {
            s1.addNumber(2);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            s1.shortestSpan();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            s2.longestSpan();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            s3.addNumber(2);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }   
    }
    {
        std::cout << "~~~~~~~ BIG NUMBERS TESTS ~~~~~~~" << std::endl;
        Span s1(1000000);
        Span s2(1000000);
        
        std::vector<int> temp1(100000);
        std::generate(temp1.begin(), temp1.end(), randomNum);
        s1.addSequence(temp1.begin(), temp1.end());
        try
        {
            std::cout << "s1 longest span: " << s1.longestSpan() << std::endl;
            std::cout << "s1 shortest span: " << s1.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        std::vector<int> temp2(900000 - 1);
        std::generate(temp2.begin(), temp2.end(), randomNum);
        s2.addSequence(temp2.begin(), temp2.end());
        try
        {
            std::cout << "s2 longest span: " << s2.longestSpan() << std::endl;
            std::cout << "s2 shortest span: " << s2.shortestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            s1.addSequence(s2.getVec().begin(), s2.getVec().end());
            std::cout << "s1 size after merge: " << s1.getVec().size() << std::endl;
            s1.addNumber(9);
            std::cout << "added 1" << std::endl;
            s1.addNumber(6);
            std::cout << "added 1" << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        } 
    }
	
	return (0);
}