/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:36:38 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/30 13:50:49 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);
		ScalarConverter	&operator=(ScalarConverter const &rhs);
        
        static void     printChar(std::string num);
        static void     printInt(std::string num);
        static void     printDouble(std::string num);
        static void     printFloat(std::string num);
        static void     printNan(void);
        static void     printInf(std::string num);
        static void     printInff(std::string num);

	public:
		static void	convert(std::string num);
};

#endif