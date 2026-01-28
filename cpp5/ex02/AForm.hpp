/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:17:17 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/28 08:47:18 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	protected:
		std::string	_name;
		bool		_signed;
		int const	_minSign;
		int const	_minExec;
        AForm		&operator=(AForm const &rhs);

	public:
		AForm(void);
		AForm(std::string name, int minSign, int minExec);
		AForm(AForm const &src);
		virtual ~AForm(void);

		bool const			&getSigned(void) const;
		int const			&getSign(void) const;
		int const			&getExec(void) const;
		std::string const	&getName(void) const;
		
		void	        beSigned(Bureaucrat const &b);
		void	        execute(Bureaucrat const &b) const;
		virtual void	executeNow(void) const = 0;

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

std::ostream	&operator<<(std::ostream &os, AForm const &src);

#endif