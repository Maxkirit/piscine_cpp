/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:38:25 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/17 16:46:01 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon{
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon(void);
		std::string const   &getType(void);
		void                setType(std::string newType);
	private:
		std::string _type;
};

#endif