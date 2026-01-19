/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:28:56 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/19 11:15:48 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

unsigned getNumberDigits (unsigned i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

std::string	trimWhitespaces(const std::string str)
{
	const std::string	whitespace = " \t\n\v\r\f";

	size_t	start = str.find_first_not_of(whitespace);
	if (start == std::string::npos)
		return ("");
	size_t	end = str.find_last_not_of(whitespace);
	return (str.substr(start, start - end + 1));
}

void	printContacts(PhoneBook *book)
{
	for (int i = 0; i < 8; i++)
	{
		if (book->list[i].getNumber() == "-1")
			break;
		std::cout << "Contact (" << i << ")" << std::endl;
		std::cout << "first name: "<< book->list[i].getFirstName() << std::endl;
		std::cout << "last name: " << book->list[i].getLastName() << std::endl;
		std::cout << "nickname : " << book->list[i].getNickname() << std::endl;
		std::cout << "secret: " << book->list[i].getSecret() << std::endl;
		std::cout << "number: " << book->list[i].getNumber() << std::endl;
	}
	return ;
}

void	printField(std::string field)
{
	if (field.length() > 10)
		std::cout << std::string(&field[0], 9) << ". | ";
	else
		std::cout << field << std::string(10 - field.length(), ' ') << " | ";
	return ;
}

int main(void)
{
	PhoneBook	book;
	std::string	cmd;

	while (1)
	{
		std::cout << "Enter command ADD, SEARCH or EXIT: ";
		std::getline(std::cin, cmd);
		cmd = trimWhitespaces(cmd);
		if (!cmd.compare("ADD"))
			book.add();
		else if (!cmd.compare("SEARCH"))
			book.search();
		else if (!cmd.compare("EXIT"))
		{
			printContacts(&book);
			return (0);
		}
		else
			std::cout << "Unknown command, try again: " << std::endl;
	}
	return (0);
}