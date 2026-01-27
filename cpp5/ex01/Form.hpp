/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:17:17 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 17:07:21 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	private:
		std::string	_name;
		bool		_signed;
		int const	_minSign;
		int const	_minExec;
		//this operator doesn't make sense here bc minSign and minExec are const
		//Kept in private to respect canonical form
		Form	&operator=(Form const &rhs);

	public:
		Form(void);
		Form(std::string name, int minSign, int minExec);
		Form(Form const &src);

		bool const			&getSigned(void) const;
		int const			&getSign(void) const;
		int const			&getExec(void) const;
		std::string const	&getName(void) const;
		
		void	beSigned(Bureaucrat const &b);

		class GradeTooHigh: public std::exception
		{
			public:
				virtual const char *what(void) const throw(){
					return ("Grade too high");
				}
		};
		
		class GradeTooLow: public std::exception
		{
			public:
				virtual const char *what(void) const throw(){
					return ("Grade too low");
				}
			
		};
};

std::ostream	&operator<<(std::ostream &os,Form const &src);

#endif