/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:22:45 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/22 19:30:28 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    {
        FragTrap    a;
        FragTrap    b(std::string("Le violoneux Ronald"));
        FragTrap    c(std::string("Le violoneux Michel"));
        FragTrap    d(c);
        FragTrap    e(std::string("Le violoneux Sylvestre"));
        FragTrap    f(std::string("Le violoneux Eric"));
        a = b;

        a.attack(d.getName());
        d.takeDamage(a.getDmg());
        a.highFiveGuys();
        a.highFiveGuys();
        d.beRepaired(3);
        a.attack(d.getName());
        d.takeDamage(a.getDmg());
        std::cout << "d hit points: " << d.getHitPoints() << ", a energy points: " << a.getEnergy() << std::endl;
        a.attack(d.getName());
        d.takeDamage(a.getDmg());
        std::cout << "d hit points: " << d.getHitPoints() << ", a energy points: " << a.getEnergy() << std::endl;
        a.attack(d.getName());
        d.takeDamage(a.getDmg());
        std::cout << "d hit points: " << d.getHitPoints() << ", a energy points: " << a.getEnergy() << std::endl;
        a.attack(d.getName());
        d.takeDamage(a.getDmg());
        std::cout << "d hit points: " << d.getHitPoints() << ", a energy points: " << a.getEnergy() << std::endl;
        a.attack(d.getName());
        d.takeDamage(a.getDmg());
        std::cout << "d hit points: " << d.getHitPoints() << ", a energy points: " << a.getEnergy() << std::endl;
        a.attack(d.getName());
        d.takeDamage(a.getDmg());
        std::cout << "d hit points: " << d.getHitPoints() << ", a energy points: " << a.getEnergy() << std::endl;
        a.attack(d.getName());
        d.takeDamage(a.getDmg());
        std::cout << "d hit points: " << d.getHitPoints() << ", a energy points: " << a.getEnergy() << std::endl;
        a.attack(d.getName());
        d.takeDamage(a.getDmg());
        std::cout << "d hit points: " << d.getHitPoints() << ", a energy points: " << a.getEnergy() << std::endl;
        a.attack(d.getName());
        d.takeDamage(a.getDmg());
        std::cout << "d hit points: " << d.getHitPoints() << ", a energy points: " << a.getEnergy() << std::endl;
        a.attack(d.getName());
        d.takeDamage(a.getDmg());
        std::cout << "d hit points: " << d.getHitPoints() << ", a energy points: " << a.getEnergy() << std::endl;
        f.attack(e.getName());
        e.takeDamage(f.getDmg());
        f.attack(e.getName());
        e.takeDamage(f.getDmg());
        e.beRepaired(2);
        e.beRepaired(2);
        e.beRepaired(2);
        e.beRepaired(2);
        e.beRepaired(2);
        std::cout << "e hit points: " << e.getHitPoints() << std::endl;
    }
    {
        ClapTrap a("the OG version");
        a.attack("");
    }
    {
        ScavTrap a("Scav Version");
        a.guardGate();
        a.guardGate();
    }
}