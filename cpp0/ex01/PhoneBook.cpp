/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:27:59 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/16 18:37:18 by mturgeon         ###   ########.fr       */
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