/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:03:15 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/25 13:46:22 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <ctime>
#include <iterator>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::list<int> lst;
		PmergeMe(void);
	public:
		PmergeMe(const std::vector<int> &v);
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &pm);
		~PmergeMe(void);

		template <typename C>
		void mergeInsertSort(C& c);
		template <typename C>
		void insertionSort(C &c,  typename C::iterator start, typename C::iterator end);
		template <typename C>
		void mergeSort(C& c, typename C::iterator start, typename C::iterator end);
		template <typename C>
		void merge(C& c, typename C::iterator start, typename C::iterator mid, typename C::iterator end);

		void sortAndPrint(void);
};

template <typename C>
void PmergeMe::mergeInsertSort(C& c)
{
	if (c.size() > 1)
		mergeSort(c, c.begin(), c.end());
}

template <typename C>
void PmergeMe::mergeSort(C& c, typename C::iterator start, typename C::iterator end)
{
	if (std::distance(start, end) <= 32)
		insertionSort(c, start, end);
	else if (std::distance(start, end) > 1)
	{
		typename C::iterator mid = start;
		std::advance(mid, std::distance(start, end) / 2);
		mergeSort(c, start, mid);
		mergeSort(c, mid, end);
		merge(c, start, mid, end);
	}
}

template <typename C>
void PmergeMe::insertionSort(C &c,  typename C::iterator start, typename C::iterator end)
{
	if (start == end)
		return;
	for (typename C::iterator it = start; it != end; ++it)
	{
		typename std::iterator_traits <typename C::iterator> ::value_type n = *it;
		typename C::iterator j = it;
		while (j != start)
		{
			typename C::iterator prev = j;
			--prev;
			if (*prev <= n)
				break;
			*j = *prev;
			j = prev;
		}
		*j = n;
	}
	(void)c;
}

template <typename C>
void PmergeMe::merge(C& c, typename C::iterator start, typename C::iterator mid, typename C::iterator end)
{
	C temp;
	typename C::iterator itStart = start;
	typename C::iterator itEnd = mid;

	while (itStart != mid && itEnd != end)
	{
		if (*itStart <= *itEnd)
		{
			temp.push_back(*itStart);
			++itStart;
		}
		else
		{
			temp.push_back(*itEnd);
			++itEnd;
		}
	}

	while (itStart != mid)
	{
		temp.push_back(*itStart);
		++itStart;
	}
	while (itEnd != end)
	{
		temp.push_back(*itEnd);
		++itEnd;
	}
	std::copy(temp.begin(), temp.end(), start);
	(void)c;
}

#endif
