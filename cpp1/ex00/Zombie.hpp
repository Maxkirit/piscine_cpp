/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:26:38 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/17 15:43:37 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void) const;
		
	private:
		std::string	_name; 
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif