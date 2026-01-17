/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 15:26:16 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/17 16:19:05 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int     zombieNum = 5;
    Zombie  *horde = zombieHorde(zombieNum, "Violoneux");

    for (int i = 0; horde != 0 && i < zombieNum; i++)
        horde[i].announce();

    delete [] horde; //use this operator when freeing arrays
	return (0);
}