/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:39:45 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/20 14:09:50 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);

	std::string		s1(argv[2]);
	std::string		s2(argv[3]);
	std::ifstream	input(argv[1]);
	std::string		buffer;
	std::string		content("");
	std::size_t		idx;
	std::size_t		found;
	std::string		newName(argv[1]);
	std::ofstream	output(newName.append(".replace").c_str());

	//read the content of the file into buffer and append it into content
	while (getline(input, buffer))
	{
		content.append(buffer);
		if (!input.eof())
			content.push_back('\n');
	}

	//find s1 in content, erase if found and replace
    idx = 0;
	found = content.find(s1, idx);
	while (found != std::string::npos)
	{
		content.erase(found, s1.length());
		content.insert(found, s2);
		idx = found + s2.length();
		found = content.find(s1, idx);
	}

	output << content << std::endl;
	return (1);
}