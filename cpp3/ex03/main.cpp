/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:22:45 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/23 14:23:39 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{

    //correct claptrap attack value in all exercises

    DiamondTrap a("Le violoneux Ronald");
    DiamondTrap b("Le violoneux Michel");
    
    a.whoAmI();
    b.whoAmI();
    a.guardGate();
    a.guardGate();
    b.guardGate();
    b.guardGate();
    a.highFiveGuys();
    b.highFiveGuys();    
    
    while (b.getHitPoints() > 0 && a.getEnergy() > 0)
    {
        a.attack(b.getName());
        if (a.getEnergy() > 0)
            b.takeDamage(a.getDmg());
        std::cout << "b hit points " << b.getHitPoints() << ", a energy points: " << a.getEnergy();
    }
    for (int i = 0; i < 3; i++)
    {
        std::cout << "\nAttempt " << (i + 1) << ":" << std::endl;
        std::cout << "b hit points " << b.getHitPoints() << ", a energy points: " << a.getEnergy();
    }
    b.beRepaired(10);
    std::cout << "b hit points " << b.getHitPoints() << ", a energy points: " << a.getEnergy();
    return (0);
}