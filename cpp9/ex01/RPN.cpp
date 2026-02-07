/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 09:32:02 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/07 10:43:09 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string const &input): _expression(input){}

RPN::RPN(RPN const &src)
{
	*this = src;
}
RPN	&RPN::operator=(RPN const &rhs)
{
		if (this != &rhs)
	{
		this->_expression = rhs._expression;
	}
	return (*this);
}

int	RPN::compute(void) const
{
	std::stringstream	manip(this->_expression);
	std::string			buffer;
	std::stack<int>		expr;
	int					num1;
	int					num2;
	
	while (manip >> buffer)
	{
		if (buffer.size() != 1)
			throw(std::runtime_error("bad input token"));
		if (isdigit(buffer[0]))
			expr.push(buffer[0] - '0');
		else
		{
			if (expr.size() < 2)
				throw (std::runtime_error("bad expression"));
			//asign vals then remove from stack immediately to reach next one
			num2 = expr.top();
			expr.pop();
			num1 = expr.top();
			expr.pop();
			expr.push(result(num1, num2, buffer[0]));
		}
	}
	if (expr.size() != 1)
		throw (std::runtime_error("bad expression"));
	return (expr.top());
}

int	RPN::result(int num1, int num2, char op) const
{
	switch (op)
	{
		case ('+'):
			return (num1 + num2);
		case ('-'):
			return (num1 - num2);
		case ('*'):
			return (num1 * num2);
		case ('/'):
		{
			if (num2 == 0)
				throw (RPN::DivByZero());
			return (num1 / num2);
		}
	}
	throw (std::runtime_error("bad operator"));
}