/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:27:35 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/19 15:17:47 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl    Cursor;

    Cursor.complain("test");
    Cursor.complain("INFO");
    Cursor.complain("");
    Cursor.complain("WARNING ");
    Cursor.complain(" WARNING ");
    Cursor.complain("warning");
    Cursor.complain("DEBUG");
    Cursor.complain("WARNING");
    Cursor.complain("ERROR");
    return (1);
}