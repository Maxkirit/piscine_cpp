/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:21:25 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/28 17:32:33 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern created." << std::endl;
}
Intern::~Intern(void)
{
	std::cout << "Intern destroyed." << std::endl;
}

AForm	*Intern::_makeShrub(std::string target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::_makePresident(std::string target) const
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::_makeRobot(std::string target) const
{
	return (new RobotomyRequestForm(target));
}

//array of pointer to wrapper functions over constructors that return pointers to AForm.
AForm	*Intern::makeForm(std::string formName, std::string target)
{
	AForm	*temp;
	AForm	*(Intern::*form[3])(std::string target) const = { &Intern::_makePresident,
																		&Intern::_makeRobot,
																		&Intern::_makeShrub};
	std::string	names[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			temp = (this->*form[i])(target);
			std::cout << "Intern made " << formName << std::endl;
			return (temp);
		}
	}
	throw(Intern::InvalidFormName(formName));
	return (0);
}

