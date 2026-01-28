/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:24:44 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/28 10:41:05 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void):
	_name(""),
	_signed(false),
	_minSign(150),
	_minExec(150)
{
	std::cout << "Nameless AForm created." << std::endl;
}

AForm::AForm(std::string name, int minSign, int minExec):
	_name(name),
	_signed(false),
	_minSign(minSign),
	_minExec(minExec)
{
	if (minSign < 1 || minExec < 1)
		throw (AForm::GradeTooHigh());
	if (minSign > 150 || minExec > 150)
		throw (AForm::GradeTooLow());
	std::cout << "AForm " << this->_name << " created." << std::endl;
}

//subject says at construction, status is not signed so even on copy, it is set to false.
AForm::AForm(AForm const &src):
	_name(src._name),
	_signed(false),
	_minSign(src._minSign),
	_minExec(src._minExec)
{
	std::cout << "AForm " << this->_name << " copied." << std::endl;
}

AForm::~AForm(void)
{
    std::cout << "Form " << this->_name << " destroyed." << std::endl;
}

bool const	&AForm::getSigned(void) const
{
	return (this->_signed);
}

int const	&AForm::getSign(void) const
{
	return (this->_minSign);
}

int const	&AForm::getExec(void) const
{
	return (this->_minExec);
}

std::string const	&AForm::getName(void) const
{
	return (this->_name);
}

std::ostream	&operator<<(std::ostream &os,AForm const &src)
{
	os << "Name: " << src.getName() << ", status: " << src.getSigned();
	os << ", lvl. to sign: " << src.getSign() << ", lvl. to exec: " << src.getExec() << ".";
	return (os);
}

void	AForm::beSigned(Bureaucrat const &b)
{
	if (this->_signed)
	{
		std::cout << "AForm " << this->_name << " has already been signed." << std::endl;
		return ;
	}
	int lvl = b.getGrade();
	if (this->_minSign >= lvl)
		this->_signed = true;
	else
		throw (AForm::GradeTooLow());
}

void    AForm::execute(Bureaucrat const &b) const
{
    if (b.getGrade() >= this->_minExec)
        throw (AForm::GradeTooLow());
    return (this->executeNow());
}