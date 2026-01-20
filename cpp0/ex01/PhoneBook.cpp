/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:27:59 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/20 13:55:49 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void){
	std::cout << "A phonebook ? How cool !" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void){
	std::cout << "This thing sucks, I'm going back to my Minitel..." << std::endl;	
}

void    PhoneBook::add(void)
{
	std::string	field = "";
	
	static int i = 0;

    while (!field.compare(""))
    {
        std::cout << "First Name: ";
        std::getline(std::cin, field);
        field = trimWhitespaces(field);
    }
	this->list[i].setFirstName(field);
    field = "";

    while (!field.compare(""))
    {
        std::cout << "Last Name: ";
        std::getline(std::cin, field);
        field = trimWhitespaces(field);
    }
	this->list[i].setLastName(field);
    field = "";

    while (!field.compare(""))
    {
        std::cout << "Nickname: ";
        std::getline(std::cin, field);
        field = trimWhitespaces(field);
    }
	this->list[i].setNickname(field);
    field = "";

    while (!field.compare(""))
    {
        std::cout << "Secret: ";
        std::getline(std::cin, field);
        field = trimWhitespaces(field);
    }
	this->list[i].setSecret(field);
    field = "";

    while (!field.compare(""))
    {
        std::cout << "Phone number: ";
        std::getline(std::cin, field);
        field = trimWhitespaces(field);
        if (field.find_first_not_of("0123456789") != std::string::npos || field.length() > 11)
        {
            std::cout << "Enter up to 10 digits only." << std::endl;
            field = "";
        }
    }
	this->list[i].setNumber(field);

	i++;
	if (i == 8)
		i = 0;
}

void	PhoneBook::search(void) const
{
	int			num;
	std::string	field;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "| (" << i + 1 << ") | ";
		printField(this->list[i].getFirstName());
		printField(this->list[i].getLastName());
		printField(this->list[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << std::endl << "Which number ? (enter index): ";
	std::getline(std::cin, field);
	field = trimWhitespaces(field);
	num = atoi(field.c_str()) - 1;
	while (num < 0 || num > 7 || this->list[num].getNumber() != "-1")
	{
		std::cout << "Enter existing contact in range [1,8]: ";
		std::getline(std::cin, field);
		field = trimWhitespaces(field);
		num = atoi(field.c_str()) - 1;
	}
	std::cout << "Contact (" << num + 1 << ")" << std::endl;
	std::cout << "first name: "<< this->list[num].getFirstName() << std::endl;
	std::cout << "last name: " << this->list[num].getLastName() << std::endl;
	std::cout << "nickname : " << this->list[num].getNickname() << std::endl;
	std::cout << "secret: " << this->list[num].getSecret() << std::endl;
	std::cout << "number: " << this->list[num].getNumber() << std::endl;
	return ;
}