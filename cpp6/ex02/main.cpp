/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:39:46 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/30 17:35:19 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Underived.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base    *generate(void)
{
	int random = rand(); 
	double stamp = (double) random / (double) RAND_MAX;

	if (stamp < 0.33)
		return (new A());
	if (stamp > 0.33 && stamp < 0.66)
		return (new B());
	else
		return (new C());

}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "p is of type A." << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "p is of type B." << std::endl;
		return ;
	}
	catch(const std::exception& e){}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "p is of type C." << std::endl;
		return ;
	}
	catch(const std::exception &e){}
	std::cout << "p is of neither types A, B or C." << std::endl;
	return ;
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "p is of type A." << std::endl;
		return ;	
	}
	if (dynamic_cast<B *>(p))
	{
		std::cout << "p is of type B." << std::endl;
		return ;
	}
	if (dynamic_cast<C *>(p))
	{
		std::cout << "p is of type C." << std::endl;
		return ;		
	}
	std::cout << "p is of neither types A, B or C." << std::endl;
	return ;	
}

int main (void)
{
	std::srand(time(0));
	Base *ptr = generate();
	Underived *udr = new Underived();

	identify(*ptr);
	identify(ptr);
	identify(*udr);
	identify(udr);
	
	delete ptr;
	delete udr;
	return (0);
}