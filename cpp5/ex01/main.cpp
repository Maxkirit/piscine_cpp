/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:57:48 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 17:19:19 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat	b1("James", 150);
	Bureaucrat	b2("Lawrence", 1);
	//using ptrs since no = overload.
	Form		*f[5];
	for (int i = 0; i < 5; i++)
		f[i] = 0;
	try
	{
		f[0] = new Form("Shoe Lacing Compliance Requirements", 150, 150);
		f[1] = new Form("Bird Migration Policy", 50, 50);
		f[2] = new Form("Desk Decoration Guidelines", 1, 1);
		f[3] = new Form("Cantina Quaterly Menus", 1, 140);
		f[4] = new Form("Halloween Curling Team Building Expense Receit", 25, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		for (int i = 0; i < 5; i++)
		{
			if (f[i])
				b1.signForm(*f[i]);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		for (int i = 0; i < 5; i++)
		{
			if (f[i])
				b2.signForm(*f[i]);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	for (int i = 0; i < 5; i++)
		delete f[i];
	return (0);
}