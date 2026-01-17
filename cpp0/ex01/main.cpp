/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:28:56 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/17 11:50:02 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

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
		if (book->list[i].getNumber() < 0)
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

//After adding contact, iterate i until book full.
//Then, start overwriting from the beginning.
void	add(PhoneBook *book)
{
	std::string	field = "";
	int			num;
	
	static int i = 0;

    while (!field.compare(""))
    {
        std::cout << "First Name: ";
        std::getline(std::cin, field);
        field = trimWhitespaces(field);
    }
	book->list[i].setFirstName(field);
    field = "";

    while (!field.compare(""))
    {
        std::cout << "Last Name: ";
        std::getline(std::cin, field);
        field = trimWhitespaces(field);
    }
	book->list[i].setLastName(field);

    while (!field.compare(""))
    {
        std::cout << "Nickname: ";
        std::getline(std::cin, field);
        field = trimWhitespaces(field);
    }
	book->list[i].setNickname(field);
    field = "";

    while (!field.compare(""))
    {
        std::cout << "Secret: ";
        std::getline(std::cin, field);
        field = trimWhitespaces(field);
    }
	book->list[i].setSecret(field);
    field = "";

    while (!field.compare(""))
    {
        std::cout << "Phone number: ";
        std::getline(std::cin, field);
        field = trimWhitespaces(field);
    }
	num = atoi(field.c_str());
	book->list[i].setNumber(num);

	i++;
	if (i == 8)
		i = 0;
}

void	printField(std::string field)
{
	if (field.length() > 10)
		std::cout << std::string(&field[0], 9) << ". | ";
	else
		std::cout << field << std::string(10 - field.length(), ' ') << " | ";
	return ;
}

void	search(PhoneBook *book)
{
	int			num;
	std::string	field;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "| (" << i + 1 << ") | ";
		printField(book->list[i].getFirstName());
		printField(book->list[i].getLastName());
		printField(book->list[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << std::endl << "Which number ? (enter index): ";
	std::getline(std::cin, field);
	field = trimWhitespaces(field);
	num = atoi(field.c_str()) - 1;
	while (num < 0 || num > 8 || book->list[num].getNumber() < 0)
	{
		std::cout << "Enter existing contact in range [1,8]: ";
		std::getline(std::cin, field);
		field = trimWhitespaces(field);
		num = atoi(field.c_str()) - 1;
	}
	std::cout << "Contact (" << num + 1 << ")" << std::endl;
	std::cout << "first name: "<< book->list[num].getFirstName() << std::endl;
	std::cout << "last name: " << book->list[num].getLastName() << std::endl;
	std::cout << "nickname : " << book->list[num].getNickname() << std::endl;
	std::cout << "secret: " << book->list[num].getSecret() << std::endl;
	std::cout << "number: " << book->list[num].getNumber() << std::endl;
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
			add(&book);
		else if (!cmd.compare("SEARCH"))
			search(&book);
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