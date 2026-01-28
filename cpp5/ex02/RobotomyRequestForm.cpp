/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:39:39 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/28 08:45:41 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void):
    AForm("", 72, 5),
    _target("")
{
    std::cout << "Nameless and targetless RobotomyRequestForm created." << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string name, std::string target):
    AForm(name, 72, 5),
    _target(target)
{
    std::cout << "RobotomyRequestForm " << this->_name << " for " << this->_target << " created." << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src):
    AForm(src._name, 72, 5),
    _target(src._target)
{
    std::cout << "RobotomyRequestForm " << this->_name << " copied." << std::endl;
}

// RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
// {
//     if (this != &rhs)
//     {
//         this->_name = rhs._name;
//         this->_target = rhs._target;
//     }
//     return (*this);
// }

std::string const	&RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void    RobotomyRequestForm::setTarget(std::string const &newTarget)
{
    this->_target = newTarget;
    return ;
}
void    RobotomyRequestForm::executeNow(void) const
{
    std::time_t time;
    std::tm     *t;

    std::time(&time);
    t = gmtime(&time);
    std::cout << "Starting lobotomy..." << std::endl << "* loud drilling noises *" << std::endl;
    if (t->tm_sec % 2 == 0)
        std::cout << this->_target << " has been successfully robotomized!" << std::endl;
    else
        std::cout << this->_target << "'s robotomy failed..." << std::endl;  
    return ;
}