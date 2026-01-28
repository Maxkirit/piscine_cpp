/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 08:04:30 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 19:15:26 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <exception>

#include "AForm.hpp"

class Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		Bureaucrat		&operator=(Bureaucrat const &rhs);  

		std::string const	&getName(void) const;
		int const			&getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

		void	signForm(AForm &form) const;
        void    executeForm(AForm const &form) const; //prints <bureaucrat> execs <forms> and calls *Form::exectute(*this)

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

        class FormNotSigned: public std::exception
        {
            public:
            	virtual const char *what(void) const throw(){
					return ("Form not signed !");
				}
        };
};

//won't redefine the class ostream to overload << and can't define it inside Bureaucrat. 
//IntelliSense
std::ostream    &operator<<(std::ostream &os, Bureaucrat const &rhs);

#endif