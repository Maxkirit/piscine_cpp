/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:42:09 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/19 09:13:17 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon &type);
		void	attack(void) const;
	private:
		std::string _name;
		Weapon		*_weaponp;
};

#endif