/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:40:48 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/28 17:27:41 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
    AForm("PresidentialPardonForm", 72, 5),
    _target("")
{
    std::cout << "Nameless and targetless PresidentialPardonForm created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
    AForm("PresidentialPardonForm", 72, 5),
    _target(target)
{
    std::cout << "PresidentialPardonForm for " << this->_target << " created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src):
    AForm("PresidentialPardonForm", 72, 5),
    _target(src._target)
{
    std::cout << "PresidentialPardonForm for " << this->_target << " copied." << std::endl;
}

std::string const	&PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void    PresidentialPardonForm::setTarget(std::string const &newTarget)
{
    this->_target = newTarget;
    return ;
}
void    PresidentialPardonForm::executeNow(void) const
{
    std::cout << this->_target << " has been (gracefully) pardoned by Zaphod Beeblerox" << std::endl;
    return ;
}