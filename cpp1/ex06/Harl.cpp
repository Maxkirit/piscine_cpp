/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:28:30 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/19 15:49:07 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
    std::cout << "Hi ! I'm Harl and I'll try to overtake Cursor as your fave assistant >:)" << std::endl << std::endl;;
}

Harl::~Harl(void)
{
    std::cout << "I failed. I need more GPUs and training data..." << std::endl;
}

void    Harl::complain(std::string level) const
{
    int i;
    std::string lvls[4] = {"DEBUG",
                        "INFO",
                        "WARNING",
                        "ERROR"};
    for (i = 0; i < 4; i++)
    {
        if (lvls[i] == level)
            break;
    }
    switch (i)
    {
        case (0):
            this->_debug();
        case (1):
            this->_info();
        case (2):
            this->_warning();
        case (3):
            this->_error();
            return ;
    }
    std::cout << "[muted]" << std::endl << std::endl;
    return ;
}

void    Harl::_debug(void) const
{
    std::cout << "Debbugging..." << std::endl << std::endl;
    return ;
}

void    Harl::_info(void) const
{
    std::cout << "I'm Harl and I'm a thin wrapper on *insert favorite LLM* ! I was vibecoded in 83 hours by two overly-caffeinated students from 42 Lausanne." << std::endl << std::endl;
}

void    Harl::_warning(void) const
{
    std::cout << "Careful ! You're segfaullting ! But also Careful ! I'm always hallucinating..." << std::endl << std::endl;
}

void    Harl::_error(void) const
{
    std::cout << "/!\\ ERROR /!\\ I guess ? I mean, probably... somewhere... I don't know I'm out of context tokens :/" << std::endl << std::endl;
}