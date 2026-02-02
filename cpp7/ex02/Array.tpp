/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturgeon <maxime.p.turgeon@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:31:55 by mturgeon          #+#    #+#             */
/*   Updated: 2026/02/02 20:48:51 by mturgeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(void): _size(0), _array(new T [0]){}

template<typename T>
Array<T>::Array(unsigned int const &n): _size(n), _array(new T [n]){}

template<typename T>
Array<T>    &Array<T>::operator=(Array<T> const &rhs)
{
    if (this != &rhs)
    {
        this->_size = rhs._size;
        delete [] this->_array;
        this->_array = new T[this->_size];
        for (size_t i = 0; i < this->_size; i++)
            this->array[i] = rhs._array[i];
    }
    return (*this);
}

template<typename T>
Array<T>::Array(Array<T> const &src)
{
    this->_size = src._size;
    delete [] this->_array;
    this->_array = new T[this->_size];
    for (size_t i = 0; i < this->_size; i++)
        this->array[i] = src._array[i];  
}

template<typename T>
Array<T>::~Array(void)
{
    delete [] this->_array;
}

template<typename T>
T   &Array<T>::operator[](size_t i)
{
    if (this->_size == 0 && i == 0)
        return (this->_array[0]);
    if (i >= this->_size)
        throw(std::out_of_range("index out of range"));
    return (this->_array[i]);
}

template<typename T>
size_t const    &Array<T>::size(void) const
{
    return (this->_size);
}

template<typename T>
void    Array<T>::setValueAtIndex(T const &val, size_t const &i)
{
    if (i >= this->_size)
        throw (std::out_of_range("index out of range"));
    this->_array[i] = val;
    return ;
}