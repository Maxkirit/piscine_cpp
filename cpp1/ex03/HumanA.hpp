/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:39:54 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/17 16:57:52 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA(void);
		void	attack(void) const;
	private:
		std::string _name;
		Weapon		&_weapon;	
};

#endif