/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 08:17:51 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 08:18:54 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void);

Bureaucrat(std::string name);

Bureaucrat(Bureaucrat const &src);

~Bureaucrat(void);

Bureaucrat  &operator=(Bureaucrat const &rhs);  

std::string const	&getName(void) const;

unsigned int    &getGrade(void) const;

void    incrementGrade(void);
void    decrementGrade(void);