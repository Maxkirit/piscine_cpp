/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:38:13 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/28 17:29:59 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm("ShrubberyCreationForm", 145, 137),
	_target("")
{
	std::cout << "Nameless and targetless ShrubberyCreationForm created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
	std::cout << "ShrubberyCreationForm for " << this->_target << " created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src):
	AForm("ShrubberyCreationForm", 145, 137),
	_target(src._target)
{
	std::cout << "ShrubberyCreationForm for " << this->_target << " copied." << std::endl;
}

std::string const	&ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void    ShrubberyCreationForm::setTarget(std::string const &newTarget)
{
	this->_target = newTarget;
	return ;
}

void	ShrubberyCreationForm::executeNow(void) const
{
	std::string     filename(this->_target);
	filename.append("_shrubbery");
	std::ofstream	file(filename.c_str());
	std::ifstream	input("forest.ascii");

	file << input.rdbuf();
	std::cout << "Forest created for " << this->_target << ". May they enjoy their peace." << std::endl;
}