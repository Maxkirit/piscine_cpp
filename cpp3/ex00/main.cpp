/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:22:45 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/22 16:46:21 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap    a;
    ClapTrap    b(std::string("Le violoneux Ronald"));
    ClapTrap    c(std::string("Le violoneux Michel"));
    ClapTrap    d(c);
    ClapTrap    e(std::string("Le violoneux Sylvestre"));
    ClapTrap    f(std::string("Le violoneux Eric"));
    a = b;

    a.attack(d.getName());
    d.takeDamage(a.getDmg());
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