/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:46:50 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/16 14:25:08 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctype.h>

int main(int argc, char **argv)
{
    int i;
    int j;
    std::string new_s;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (i = 1; i < argc; i++)
        {
            for (j = 0; argv[i][j] != '\0'; j++)
                argv[i][j] = std::toupper(argv[i][j]);
            if (argv[i][0])
                std::cout << argv[i] << std::endl;
        }
    }
    return (0);
}