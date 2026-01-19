/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:28:35 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/19 11:14:14 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void):_number("-1"){
	std::cout << "Empty contact initialized" <<  std::endl;
	return;
};

Contact::~Contact(void){
	if (this->_number == "-1")
		return ;
	std::cout << "Contact ";
	if (!this->_firstName.empty())
		std::cout << "'" <<  this->_firstName << "' "; 
	std::cout << "deleted." << std::endl;
	return ;
};

void Contact::setFirstName(std::string str){
	this->_firstName = str;
	return ;
}

void Contact::setLastName(std::string str){
	this->_lastName = str;
	return ;
}

void Contact::setNickname(std::string str){
	this->_nickname = str;
	return ;
}

void Contact::setSecret(std::string str){
	this->_secret = str;
	return ;
}

void	Contact::setNumber(std::string n){
	this->_number = n;
	return ;
}

std::string Contact::getFirstName(void) const{
	return (this->_firstName);
}

std::string Contact::getLastName(void) const{
	return (this->_lastName);
}
std::string Contact::getNickname(void) const{
	return (this->_nickname);
}

std::string Contact::getSecret(void) const{
	return (this->_secret);
}

std::string Contact::getNumber(void) const{
	return (this->_number);
}