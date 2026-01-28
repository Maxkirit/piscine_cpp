/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:38:29 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/28 08:44:44 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;
		virtual void    executeNow(void) const;
        RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string name, std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);

		

		std::string const	&getTarget(void) const;
		void				setTarget(std::string const &newTarget);
};

#endif