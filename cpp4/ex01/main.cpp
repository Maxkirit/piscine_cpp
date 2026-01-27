/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:20:57 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/27 11:24:27 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <sstream>

int main(void)
{
    Animal *array[10];
    std::stringstream oss;
    Cat *temp1;
    Dog *temp2;
    
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            oss << "Michel [" << i << "]";
            array[i] = new Cat(oss.str());
            oss.str("");
            for (int j = 0; j < 10; j++)
            {
                oss << "I don't like chairs with " << i + j << " legs..";
                temp1 = reinterpret_cast <Cat *>(array[i]);
                temp1->setIdea(oss.str(), j);
                oss.str("");
            }
        }
        else
        {
            oss << "Ronald [" << i << "]";
            array[i] = new Dog(oss.str());
            oss.str("");
            for (int j = 0; j < 10; j++)
            {
                oss << "I hate stools with " << i + j << " legs..";
                temp2 = reinterpret_cast <Dog *>(array[i]);
                temp2->setIdea(oss.str(), j);
                oss.str("");
            }
        }
        (*array[i]).makeSound();
    }
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            temp1 = reinterpret_cast <Cat *>(array[i]);
            std::cout << temp1->getIdea(0) << std::endl;
        }
        else
        {
            temp2 = reinterpret_cast <Dog *>(array[i]);
            std::cout << temp2->getIdea(0) << std::endl;
        }
    }
    Cat test("Tester");
    test.setIdea("I'm a cat !!", 0);
    Cat copy(test);
    std::cout << "test: " << test.getIdea(0) << std::endl;
    std::cout << "copy: " << copy.getIdea(0) << std::endl;
    copy.setIdea("I'm a dog now !!", 0);
    std::cout << "test: " << test.getIdea(0) << std::endl;
    std::cout << "copy: " << copy.getIdea(0) << std::endl;
    for (int i = 0; i < 10; i++)
        delete array[i];
    return (0);
}