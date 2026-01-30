/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:48:45 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/30 15:27:06 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(void): _val(0){}

Data::Data(int val): _val(val){}

Data::Data(Data const &src): _val(src._val){}

Data    &Data::operator=(Data const &rhs)
{
    if (this != &rhs)
    {
        this->_val = rhs._val; 
    }
    return (*this);
}

int const   &Data::getVal(void) const{
    return (this->_val);
}

void    Data::setVal(int newVal)
{
    this->_val = newVal;
    return ;
}

Data::~Data(void){}
