/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:26:16 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/17 15:44:26 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie	z1("Le violoneux Daniel");
	Zombie	*z2 = newZombie("Le violoneux Michel");

	z1.announce();
	z2->announce();
	randomChump("Le violoneux Donald");
	delete z2;
	return (0);
}