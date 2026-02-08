/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 11:28:50 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/08 18:08:47 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::string validateInput(char **argv)
{
	std::stringstream	sequence;
	if (!*argv)
		throw (std::runtime_error("missing number sequence"));
	for (int i = 0; argv[i] != 0; i++)
	{
		std::string elem(argv[i]);
		if (elem.find_first_not_of("0123456789") != std::string::npos || strtoul(elem.c_str(), nullptr, 10) > INT32_MAX)
			throw (std::runtime_error("non unsigned int elem in input"));
		sequence << elem << " ";
	}
	return (sequence.str());
}

int main(int argc, char **argv)
{
	(void)argc;
	std::string	input;
	try
	{
		input = validateInput(&argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}

	PmergeMe	toSort(input);

	std::cout << "~~~~~~~ORIGINAL SEQUENCE~~~~~~~" << std::endl;
	std::cout << input << std::endl;

	double	timeVec = toSort.sortVec();
	double	timeList = toSort.sortList();

	std::cout << "~~~~~~~SORTED SEQUENCE~~~~~~~" << std::endl;
	for (std::vector<unsigned int>::const_iterator it = toSort.getVecSorted().begin(); it != toSort.getVecSorted().end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "Time to sort w/ vector: " << timeVec << " ms" << std::endl;
	std::cout << "Time to sort w/ list:   " << timeList << " ms" << std::endl;
	
	return (0);
}