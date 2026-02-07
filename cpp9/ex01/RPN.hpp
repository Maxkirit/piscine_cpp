/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 09:31:36 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/07 10:59:41 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class RPN
{
	private:
		std::string	_expression;

		int	result(int	num1, int num2, char op) const;
		RPN(void);
		
	public:
		RPN(std::string const &input);
		RPN(RPN const &src);
		RPN	&operator=(RPN const &rhs);

		int	compute(void) const;
		class DivByZero: public std::exception
		{
			public:
				virtual const char *what() const throw(){return ("division by 0");}
		};
};

#endif