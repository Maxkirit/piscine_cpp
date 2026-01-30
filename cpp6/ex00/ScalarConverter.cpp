/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:41:38 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/30 17:59:30 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	isWhitespaceLegal(std::string &input)
{
	const std::string	whitespace = " \t\n\v\r\f";
	size_t 				start = input.find_first_not_of(whitespace);
	if (start == std::string::npos)
		throw (std::invalid_argument(input));
	size_t end = input.find_last_not_of(whitespace);
	input = input.substr(start, end - start + 1);
	if (input.find_first_of(whitespace) != std::string::npos)
		throw (std::invalid_argument(input));
	return ;
}

void    ScalarConverter::printChar(std::string num)
{
	std::cout << "in char" << std::endl;
	std::cout << "char: ";
	if (num[0] < 0)
		std::cout << "impossible" << std::endl;
	else if (num[0] == 127 || (num[0] >= 0 && num[0] <= 32))
		std::cout << "not printable" << std::endl;
	else
		std::cout << "'" <<  num[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(num[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(num[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed <<  std::setprecision(2) << static_cast<double>(num[0]) << std::endl;
	return ;
}

void    ScalarConverter::printInt(std::string num)
{
	std::cout << "in int" << std::endl;
    if ((num[0] == '+' || num[0] == '-') && (num.substr(1, num.length() - 1).find_first_not_of("0123456789") != std::string::npos))
		throw (std::invalid_argument(num));
	if ((num[0] != '-' && num[0] != '+') && (num.substr(0, num.length()).find_first_not_of("0123456789") != std::string::npos))
		throw (std::invalid_argument(num));
	long input = atol(num.c_str());
	std::cout << "char: ";
	if (num.length() == 1)
		std::cout << "'" << num[0] << "'" << std::endl;
	else if (input > 255 || input < 0)
		std::cout << "impossible" << std::endl;
	else if (static_cast<char>(input) == 127 || (static_cast<char>(input) >= 0 && static_cast<char>(input) <= 32))
		std::cout << "not printable" << std::endl;
	else
		std::cout << "'" <<  static_cast<char>(input) << "'" << std::endl;
	std::cout << "int: ";
	if (input < std::numeric_limits<int>::min() || input > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(input) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(input) << "f" << std::endl;
	std::cout << "double: " << std::fixed <<  std::setprecision(2) << static_cast<double>(input) << std::endl;
	return ;
}

void    ScalarConverter::printFloat(std::string num)
{
	std::cout << "in float" << std::endl;
	if (num.find_first_of(".") == std::string::npos)
		throw (std::invalid_argument(num));
	if ((num[0] == '+' || num[0] == '-') && (num.substr(1, num.length() - 2).find_first_not_of(".0123456789") != std::string::npos))
		throw (std::invalid_argument(num));
	if ((num[0] != '-' && num[0] != '+') && (num.substr(0, num.length() - 1).find_first_not_of(".0123456789") != std::string::npos))
		throw (std::invalid_argument(num));
	int dotCount = 0;
	for (size_t i = 0; i < num.length(); i++)
	{
		if (num[i] == '.')
			dotCount++;
		if (dotCount > 1)
			throw (std::invalid_argument(num));
	}
	float input = atof(num.c_str());
	std::cout << "char: ";
	if (input > 255 || input < 0)
		std::cout << "impossible" << std::endl;
	else if (static_cast<char>(input) == 127 || (static_cast<char>(input) >= 0 && static_cast<char>(input) <= 32))
		std::cout << "not printable" << std::endl;
	else
		std::cout << "'" <<  static_cast<char>(input) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(input) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << input << "f" << std::endl;
	std::cout << "double: " << std::fixed <<  std::setprecision(2) << static_cast<double>(input) << std::endl;
	return ;
}

void    ScalarConverter::printDouble(std::string num)
{
	std::cout << "in double" << std::endl;
	if ((num[0] == '+' || num[0] == '-') && (num.substr(1, num.length() - 1).find_first_not_of(".0123456789") != std::string::npos))
		throw (std::invalid_argument(num));
	if ((num[0] != '-' && num[0] != '+') && (num.substr(0, num.length()).find_first_not_of(".0123456789") != std::string::npos))
		throw (std::invalid_argument(num));
	int dotCount = 0;
	for (size_t i = 0; i < num.length(); i++)
	{
		if (num[i] == '.')
			dotCount++;
	}
    if (dotCount != 1)
		throw (std::invalid_argument(num));
	double input = strtod(num.c_str(), 0);
	std::cout << "char: ";
	if (input > 255 || input < 0)
		std::cout << "impossible" << std::endl;
	else if (static_cast<char>(input) == 127 || (static_cast<char>(input) >= 0 && static_cast<char>(input) <= 32))
		std::cout << "not printable" << std::endl;
	else
		std::cout << "'" <<  static_cast<char>(input) << "'" << std::endl;
    std::cout << "int: ";
	if (input < std::numeric_limits<int>::min() || input > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(input) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(input) << "f" << std::endl;
	std::cout << "double: " << std::fixed <<  std::setprecision(2) << input << std::endl;
	return ;
}
void	ScalarConverter::printNan(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
	return ;
}

void	ScalarConverter::printInf(std::string num)
{
	std::cout << "in Inf" << std::endl;
	double input = std::numeric_limits<double>::infinity();
	if (num[0] == '-')
		input *= -1;
	else if (num[0] != '+')
		throw (std::invalid_argument(num));
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << std::fixed << "float: " << static_cast<float>(input) << std::endl;
	std::cout << std::fixed << "double: " << input << std::endl;
	return ;
}

void	ScalarConverter::printInff(std::string num)
{
	std::cout << "in Inff" << std::endl;
	float input = std::numeric_limits<float>::infinity();
	if (num[0] == '-')
		input *= -1;
	else if (num[0] != '+')
		throw (std::invalid_argument(num));
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << std::fixed << "float: " << input << std::endl;
	std::cout << std::fixed <<"double: " << static_cast<double>(input) << std::endl;
	return ;
}

//handle NaN (lowercase), -inf, +inf, INT_MAX?, etc. Included in cmaths
void    ScalarConverter::convert(std::string num)
{
	try
	{
		isWhitespaceLegal(num);
		for (size_t i = 0; i < num.length(); i++)
			num[i] = tolower(num[i]);
		if (num == "nan" || num == "nanf")
			return (printNan());
		if (std::string(&num[1]) == "inf")
			return (printInf(num));
		if (std::string(&num[1]) == "inff")
			return (printInff(num));
		if (num.find_first_of("f") == num.length() - 1)
			return (printFloat(num));
		if (num.find_first_not_of("+-0123456789") == std::string::npos && num.length() < 11)
			return (printInt(num));
		if (num.find_first_not_of("+-.0123456789") == std::string::npos)
			return (printDouble(num));
		if (num.length() == 1)
			return (printChar(num));
		throw(std::invalid_argument(num));
	}
	catch (std::exception const &e)
	{
		std::cerr << "Bad input: " << e.what() << std::endl;
	}
}
