/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:13:43 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 15:08:37 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    {   
        std::cout << "---------TEST1--------"  <<std::endl;
        Bureaucrat b1;
        Bureaucrat b2;
        Bureaucrat b3;
        Bureaucrat b4;

        //initialization block
        try
        {
            //operator = returns reference so valid outside of scope
            b1 = Bureaucrat("James", 150);
            std::cout << b1;
            b2 = Bureaucrat("Patrick", 1);
            std::cout << b2;
            b3 = Bureaucrat("Kevin", 0);
            std::cout << b3;
            b4 = Bureaucrat("Jimmy", 151);
            std::cout << b4 << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            b2.decrementGrade();
            std::cout << b2;
            b2.incrementGrade();
            std::cout << b2;
            b2.incrementGrade();
            std::cout << b2;
            b2.incrementGrade();
            std::cout << b2;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            b1.incrementGrade();
            std::cout << b1;
            b1.decrementGrade();
            std::cout << b1;
            b1.decrementGrade();
            std::cout << b1;
            b1.decrementGrade();
            std::cout << b1;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    {
        std::cout << "---------TEST2--------"  <<std::endl;
        Bureaucrat *b1 = 0;
        Bureaucrat *b2 = 0;
        Bureaucrat *b3 = 0;
        Bureaucrat *b4 = 0;
        try
        {
            b1 = new Bureaucrat("Eric", 1);
            b2 = new Bureaucrat("Lawrence", 150);
            b3 = new Bureaucrat("Tom", 151);
            b4 = new Bureaucrat("Lawrence", 0);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            b2->decrementGrade();
            std::cout << b2;
            b2->incrementGrade();
            std::cout << b2;
            b2->incrementGrade();
            std::cout << b2;
            b2->incrementGrade();
            std::cout << b2; 
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            b1->incrementGrade();
            std::cout << b1;
            b1->decrementGrade();
            std::cout << b1;
            b1->decrementGrade();
            std::cout << b1;
            b1->decrementGrade();
            std::cout << b1;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        delete b1;
        delete b2;
        delete b3;
        delete b4;
    }
    return (0);
}