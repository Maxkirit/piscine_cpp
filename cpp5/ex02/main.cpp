/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:57:28 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 19:20:06 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat  b1("Pierre", 145);
    Bureaucrat  b2("Paul", 72);
    Bureaucrat  b3("Jacques", 5);
    AForm       *f[5];
    for (int i = 0; i < 5; i++)
        f[i] = 0;
    f[0] = new ShrubberyCreationForm("first", "home");
    f[1] = new ShrubberyCreationForm("second", "work");
    f[2] = new RobotomyRequestForm("MyFirstRobotomy!", "me");
    f[3] = new RobotomyRequestForm("TheirFirstLobotomy", "them");
    f[4] = new PresidentialPardonForm("TheOne", "TheBoss");


    std::cout << "-----SIGINING PHASE------" << std::endl << std::endl;
    try
    {
        for (int i = 0; i < 5; i++)
            b1.signForm(*f[i]);
    }
    catch(const std::exception& e)
    {
        std::cerr << b1.getName() << ": " << e.what() << '\n';
    }
    try
    {
        for (int i = 0; i < 5; i++)
            b2.signForm(*f[i]);
    }
    catch(const std::exception  &e)
    {
        std::cerr << b2.getName() << ": " << e.what() << '\n';
    }
    try
    {
        for (int i = 0; i < 5; i++)
            b3.signForm(*f[i]);
    }
    catch(const std::exception& e)
    {
        std::cerr << b3.getName() << ": " << e.what() << '\n';
    }
    
    std::cout << "-----EXECUTING PHASE------" << std::endl << std::endl;
    try
    {
        for (int i = 0; i < 5; i++)
            b1.executeForm(*f[i]);
    }
    catch(const Bureaucrat::FormNotSigned &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        for (int i = 0; i < 5; i++)
            b2.executeForm(*f[i]);
    }
    catch(const Bureaucrat::FormNotSigned &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        for (int i = 0; i < 5; i++)
            b3.executeForm(*f[i]);
    }
    catch(const Bureaucrat::FormNotSigned &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < 5; i++)
        delete f[i];
    return (0);
}