/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:42:54 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/25 14:55:37 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _arr(NULL), _size(0)
{
	std::cout << "Array default costructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int size) : _arr(new T[size]), _size(size)
{
	for (unsigned int i = 0; i < size; i++)
		_arr[i] = 0;
	std::cout << "Array costructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &copy) : _arr(new T[copy._size]), _size(copy._size)
{
	for (unsigned int i = 0; i < _size; ++i)
		_arr[i] = copy._arr[i];
	std::cout << "Array copy costructor called" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &a)
{
	if (this != &a)
	{
		delete[] _arr;
		_size = a._size;
		_arr = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_arr[i] = a._arr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _arr;
	std::cout << "Array destructor called" << std::endl;
}

template<class T>
T &Array<T>::operator[](int i)
{
	if (i < 0)
		throw std::out_of_range("Only positive index");
	else if (static_cast <unsigned int> (i) >= this->_size)
		throw std::out_of_range("Index is over size of array");
	return this->_arr[i];
}

template<class T>
unsigned int Array<T>::size(void) const
{
	return _size;
}

#endif