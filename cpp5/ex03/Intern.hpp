/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:17:06 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/28 17:32:21 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	private:
		Intern(Intern const &src);
		Intern	&operator=(Intern const &rhs);
		AForm	*_makeShrub(std::string target) const;
		AForm	*_makeRobot(std::string target) const;
		AForm	*_makePresident(std::string target) const;

	public:
		Intern(void);
		~Intern(void);

		AForm	*makeForm(std::string formName, std::string target);
		
		class InvalidFormName: public std::exception
		{
			private:
				std::string _name;
			public:
				InvalidFormName(std::string name): _name(name){}
                ~InvalidFormName() throw(){}
				virtual const char *what(void) const throw(){
                    std::cerr << "Invalid form " << this->_name << ": ";
					return ("no form of this type available.");}
		};
};

#endif