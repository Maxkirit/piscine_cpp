/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:39:52 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/28 08:44:49 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string	    _target;
		virtual void    executeNow(void) const;
        PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string name, std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);

		

		std::string const	&getTarget(void) const;
		void				setTarget(std::string const &newTarget);
};

#endif