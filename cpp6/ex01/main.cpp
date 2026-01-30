/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:57:51 by mturgeon          #+#    #+#             */
/*   Updated: 2026/01/30 15:26:31 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data    *ptr1 = new Data(5);
	Data    *ptr2 = new Data(10);
	uintptr_t test1;
	uintptr_t test2;

	test1 = Serializer::serialize(ptr1);
	test2 = Serializer::serialize(ptr2);
	
	std::cout << "sizeof(Data *ptr): " << sizeof(ptr1) << std::endl;
	std::cout << "sizeof(unintptr_t): " << sizeof(test1) << std::endl <<std::endl;

	std::cout << "*ptr1, *ptr2: " << ptr1->getVal() << ", " << ptr2->getVal() << std::endl;
	std::cout << "ptr1, ptr2: " << ptr1 << ", " << ptr2 << std::endl;
	std::cout << "test1, test2 (serialized): " << test1 << ", " << test2 << std::endl << std::endl;

	ptr1 = Serializer::deserialize(test1);
	ptr2 = Serializer::deserialize(test2);
	std::cout << "deserialized:" << std::endl;
	std::cout << "*ptr1, *ptr2: " << ptr1->getVal() << ", " << ptr2->getVal() << std::endl;
	std::cout << "ptr1, ptr2: " << ptr1 << ", " << ptr2 << std::endl << std::endl;
	
	Data	*ptr3 = Serializer::deserialize(test1);
	Data	*ptr4 = Serializer::deserialize(test2);
	ptr3->setVal(666);
	ptr4->setVal(44);
	
	std::cout << "after change through ptr3, ptr4:" << std::endl;
	std::cout << "*ptr1, *ptr2: " << ptr1->getVal() << ", " << ptr2->getVal() << std::endl;
	
	delete ptr3;
	delete ptr4;
	return (1);
}