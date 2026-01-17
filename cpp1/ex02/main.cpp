/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:23:07 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/17 16:30:48 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string string= "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "string's address: " << &string << std::endl;
    std::cout << "stringPTR's content: " << stringPTR << std::endl;
    std::cout << "stringREF's address held: " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "string: " << string << std::endl;
    std::cout << "stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;
 
}