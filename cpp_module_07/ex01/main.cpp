/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:19:56 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/25 14:00:31 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void print(const T& value)
{
	std::cout << value << std::endl;
}

int main(void) 
{
	int iArr[] = {1, 2, 3, 4, 5};
	std::size_t iArrSize = sizeof(iArr) / sizeof(iArr[0]);
	iter(iArr, iArrSize, print<int>);

	double dArr[] = {1.1, 2.2, 3.3};
	std::size_t dArrSize = sizeof(dArr) / sizeof(dArr[0]);
	iter(dArr, dArrSize, print <double>);

	std::string sArr[] = {"Hello", "World", "Test"};
	std::size_t sArrSize = sizeof(sArr) / sizeof(sArr[0]);
	iter(sArr, sArrSize, print <std::string>);

	return 0;
}