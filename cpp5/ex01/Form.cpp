/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:24:44 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 17:08:02 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void):
	_name(""),
	_signed(false),
	_minSign(150),
	_minExec(150)
{
	std::cout << "Nameless form created." << std::endl;
}

Form::Form(std::string name, int minSign, int minExec):
	_name(name),
	_signed(false),
	_minSign(minSign),
	_minExec(minExec)
{
	if (minSign < 1 || minExec < 1)
		throw (Form::GradeTooHigh());
	if (minSign > 150 || minExec > 150)
		throw (Form::GradeTooLow());
	std::cout << "Form " << this->_name << " created." << std::endl;
}

//subject says at construction, status is not signed so even on copy, it is set to false.
Form::Form(Form const &src):
	_name(src._name),
	_signed(false),
	_minSign(src._minSign),
	_minExec(src._minExec)
{
	std::cout << "Form " << this->_name << " copied." << std::endl;
}

bool const	&Form::getSigned(void) const
{
	return (this->_signed);
}

int const	&Form::getSign(void) const
{
	return (this->_minSign);
}

int const	&Form::getExec(void) const
{
	return (this->_minExec);
}

std::string const	&Form::getName(void) const
{
	return (this->_name);
}

std::ostream	&operator<<(std::ostream &os,Form const &src)
{
	os << "Name: " << src.getName() << ", status: " << src.getSigned();
	os << ", lvl. to sign: " << src.getSign() << ", lvl. to exec: " << src.getExec() << ".";
	return (os);
}

void	Form::beSigned(Bureaucrat const &b)
{
	if (this->_signed)
	{
		std::cout << "Form " << this->_name << " has already been signed." << std::endl;
		return ;
	}
	int lvl = b.getGrade();
	if (this->_minSign >= lvl)
		this->_signed = true;
	else
		throw (Form::GradeTooLow());
}