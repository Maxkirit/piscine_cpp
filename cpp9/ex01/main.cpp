/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 09:31:13 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/07 11:20:01 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	evaluateExpression(std::string expr, std::string result)
{
	RPN	expression(expr);
	int res = expression.compute();
	if (res != atoi(result.c_str()))
		std::cout << "Error: wrond compute result /!\\" << std::endl;
	else
		std::cout << res << std::endl;
	return ;

}

void	runTest(std::string filename)
{
	std::ifstream			file(filename);
	int						index = 1;
	std::string				buffer;
	std::string				RPN;
	std::string				standardExpr;
	std::string				result;
	std::string::iterator 	it;
	std::string::iterator 	itMid;

	while (getline(file, buffer))
	{
		for (it = buffer.begin(); *it != ','; it++)
		RPN = std::string(buffer.begin(), it + 1);
		it++;
		itMid = it;
		for (it = itMid; *it != ','; it++);
		standardExpr = std::string(itMid, it);
		it++;
		result = std::string(it, buffer.end());
		std::cout << "(" << index << "): " << "RPN: " << RPN << ", Std: " << standardExpr << ", Res: ";
		evaluateExpression(RPN, result);
		index++;
	}
	return ;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: input only one input string" << std::endl;
		return (1);
	}
	
	std::string	input(argv[1]);

	if (input == "test.txt")
	{
		try
		{
			runTest(input);
			return(0);
		}
		catch (const RPN::DivByZero &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return (1);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error" <<  std::endl;
			return (1);
		}
	}
	else
	{	
		if (input.find_first_not_of("0123456789 +-*/") != std::string::npos)
		{
			std::cout << "Error" << std::endl;
			return (1);
		}
		try
		{
			RPN	expression(input);
			std::cout << expression.compute() << std::endl;
		}
		catch (const RPN::DivByZero &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return (1);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error" <<  std::endl;
			return (1);
		}
	}
	return (0);
}
	