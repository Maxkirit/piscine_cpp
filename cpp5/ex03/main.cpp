/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:57:28 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/28 16:07:25 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
    {        
        Intern a1;
        AForm *f[3] = {0, 0, 0};
        try
        {   f[0] = a1.makeForm("PresidentialPardonForm", "Joe");
            f[1] = a1.makeForm("RobotomyRequestForm", "Mary");
            f[2] = a1.makeForm("ShrubberyCreationForm", "Pokemon");
        }
        catch (std::exception const &e)
        {   
            std::cerr << e.what() << std::endl;
            for (int i = 0; i < 3; i++)
            {
                if (f[i])
                    delete f[i];
            }
            std::cout << "program ends on bad forms." << std::endl;
            return (1);
        }
        Bureaucrat b1("James", 1);
        Bureaucrat b2("Alex", 140);

        try
        {
            for (int i = 0; i < 3; i++)
            {
                if (f[i])
                    b2.signForm(*f[i]);
            }
        }
        catch (std::exception const &e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            for (int i = 0; i < 3; i++)
            {
                if (f[i])
                    b2.executeForm(*f[i]);
            }
        }
        catch (std::exception const &e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            for (int i = 0; i < 3; i++)
            {
                if (f[i])
                    b2.signForm(*f[i]);
            }
        }
        catch (std::exception const &e)
        {
            std::cout << e.what() << std::endl;
        }
        try
        {
            for (int i = 0; i < 3; i++)
            {
                if (f[i])
                    b2.executeForm(*f[i]);
            }
        }
        catch (std::exception const &e)
        {
            std::cout << e.what() << std::endl;
        }
        for (int i = 0; i < 3; i++)
            delete f[i];
    }
    std::cout << "\nNEW TESTS\n" << std::endl;
    {
        Intern		bob;
        AForm		*form;
        Bureaucrat	karen("Karen", 50);

        // Test how all forms are created properly execpt for the last one
        try
        {
            form = bob.makeForm("RobotomyRequestForm", "Alice");
            delete form;
            form = bob.makeForm("shrubbery creation", "Charlie");
            delete form;
            form = bob.makeForm("presidential pardon", "David");
            delete form;
            form = bob.makeForm("random request", "Elisa");
            delete form;
        }
        catch (std::exception &e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        // Test some Actions with available form
        std::cout << "------------------------------------" << std::endl;
        form = bob.makeForm("ShrubberyCreationForm", "Fred");
        form->beSigned(karen);
        karen.executeForm(*form);
        delete form;
        std::cout << "------------------------------------" << std::endl;
        form = bob.makeForm("PresidentialPardonForm", "Georgia");
        karen.signForm(*form);
        karen.executeForm(*form);
        delete form;
        return (0);
    }
}