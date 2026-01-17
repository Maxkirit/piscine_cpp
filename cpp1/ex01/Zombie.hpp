/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:26:38 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/17 16:06:12 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
	public:
        Zombie(); //default constructor to allow for 
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void) const;
        void    setName(std::string name);		
	private:
		std::string	_name; 
};

Zombie	*newZombie(std::string name);
Zombie *zombieHorde(int N, std::string name);

#endif