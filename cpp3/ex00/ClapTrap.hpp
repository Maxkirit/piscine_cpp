/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:18:24 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/22 16:28:17 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap(void);

		ClapTrap    &operator=(ClapTrap const &rhs);

		void        attack(const std::string &target);
		void        takeDamage(unsigned int amount);
		void        beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergy(void) const;
		int			getDmg(void) const;
		
	private:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDmg;
};

#endif