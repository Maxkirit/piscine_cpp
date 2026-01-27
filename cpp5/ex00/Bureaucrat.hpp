/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 08:04:30 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 09:01:40 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <exception>

class Bureaucrat
{
	private:
		std::string const   _name;
		unsigned int        _grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		Bureaucrat		&operator=(Bureaucrat const &rhs);  

		std::string const	&getName(void) const;
		unsigned int		getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
};

//won't redefine the class ostream to overload << and can't define it inside Bureaucrat. 
//IntelliSense
std::ostream    &operator<<(std::ostream &os, Bureaucrat const &rhs);

#endif