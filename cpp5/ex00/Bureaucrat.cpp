/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 08:17:51 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 14:22:42 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream    &operator<<(std::ostream &os, Bureaucrat const &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (os); 
}

Bureaucrat::Bureaucrat(void):
	_name(""),
	_grade(150)
{
	std::cout << "Nameless bureaucrat created." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):
	_name(name)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooHigh());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooLow());
	else
		this->_grade = grade;
	std::cout << this->_name << " created." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src):
	_name(src._name),
	_grade(src._grade)
{
	std::cout << this->_name << " copied." << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << this->_name << " destroyed." << std::endl;
}

Bureaucrat  &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_grade = rhs._grade;

	}
	return (*this);
}

std::string const	&Bureaucrat::getName(void) const{
	return (this->_name);
}

int const    &Bureaucrat::getGrade(void) const{
	return (this->_grade);
}

void    Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooHigh());
	this->_grade--;
	return ;
}
void    Bureaucrat::decrementGrade(void){
	if (this->_grade == 150)
		throw (Bureaucrat::GradeTooLow());
	this->_grade++;
	return ;
}