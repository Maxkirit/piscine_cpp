/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:15:56 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/07 09:37:00 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	is_empty(std::ifstream	&file)
{
	return (file.peek() == std::ifstream::traits_type::eof());
}


int	main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: enter one valid filename." << std::endl;
		return (1);
	}
	
	try
	{
		std::ifstream   data("data.csv");
		std::ifstream	input(argv[1]);
		if (is_empty(data) || is_empty(input))
			throw (std::runtime_error("empty file"));
		BitcoinExchange	exchange(data);
		exchange.convert(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
        return (1);
	}
	return (0);
}