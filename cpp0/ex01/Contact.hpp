/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:27:26 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/19 11:14:28 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact{
	public:
		Contact(void);
		~Contact(void);
		void 		setFirstName(std::string str);
		void 		setLastName(std::string str);
		void 		setNickname(std::string str);
		void 		setSecret(std::string str);
		void 		setNumber(std::string n);
		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickname(void) const;
		std::string	getSecret(void) const;
		std::string	getNumber(void)	const;
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string	_number;
		std::string _secret;
};

#endif