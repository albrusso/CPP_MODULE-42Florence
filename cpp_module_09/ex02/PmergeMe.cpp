/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:03:31 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/25 13:46:09 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	std::cout << "PmergeMe default costructor called" << std::endl;
}

PmergeMe::PmergeMe(const std::vector<int>& v) : vec(v), lst(v.begin(), v.end())
{
	std::cout << "PmergeMe costructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy) : vec(copy.vec), lst(copy.lst.begin(), copy.lst.end())
{
	std::cout << "PmergeMe copy costructor called" << std::endl;
} 

PmergeMe &PmergeMe::operator=(const PmergeMe &pm)
{
	if (this != &pm)
	{
		vec = pm.vec;
		lst = pm.lst;
	}
	return *this;
}

PmergeMe::~PmergeMe(void)
{
	std::cout << "PmergeMe destructor called" << std::endl;
}

void PmergeMe::sortAndPrint(void)
{
	std::cout << "Input: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	clock_t start = clock();
	mergeInsertSort(vec);
	clock_t end = clock();
	double vectorSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Output vector: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	std::cout << "Tempo vector: " << vectorSortTime << " secondi" << std::endl;

	start = clock();
	mergeInsertSort(lst);
	end = clock();
	double listSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << "Output list: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Tempo list: " << listSortTime << " secondi" << std::endl;
}
