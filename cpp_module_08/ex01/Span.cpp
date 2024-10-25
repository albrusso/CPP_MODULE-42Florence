/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:43:05 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/25 14:48:50 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	std::cout << "Span default costructor called" << std::endl;
}

Span::Span(unsigned int n) : _n (n)
{
	_v.reserve(n);
	std::cout << "Span costructor called" << std::endl;
}

Span::Span(const Span &copy)
{
	_n = copy._n;
	_v = copy._v;
	std::cout << "Span copy costructor called" << std::endl;
}

Span &Span::operator=(const Span &s)
{
	if (this != &s)
	{
		this->_n = s._n;
		this->_v = s._v;
	}
	return *this;
}

Span::~Span(void)
{
	std::cout << "Span destructor called" << std::endl;
}

int Span::operator[](int i)
{
	if (i < 0 || i > static_cast <int> (this->_n))
		throw std::out_of_range("Index is out of range !");
	return this->_v[i];
}

unsigned int Span::getSize(void)
{
	return _n;
}

void Span::addNumber(int num)
{
	if (_v.size() > _n)
	{
		std::cout << "Container is full" << std::endl;
		return ;
	}
	_v.push_back(num);
}

int Span::longestSpan(void)
{
	if (_v.size() < 2)
		throw std::logic_error("To calculate longest span need atleast two numbers, add this");
	std::vector <int>::iterator itMax = std::max_element(_v.begin(), _v.end());
	std::vector <int>::iterator itMin = std::min_element(_v.begin(), _v.end());

	return *itMax - *itMin;
}

int Span::shortestSpan(void)
{
	if (_v.size() < 2)
			throw std::logic_error("To calculate shortest span need atleast two numbers, add this");
	int min = 2147483647;
	std::vector <int> copy = _v;
	std::sort(copy.begin(), copy.end());
	std::vector <int> ::iterator itCurr = copy.begin();
	std::vector <int> ::iterator itNext = itCurr + 1;

	while (itNext != copy.end())
	{
		int diff = *itNext - *itCurr;
		if (diff < min)
			min = diff;
		itCurr++;
		itNext = itCurr + 1;
	}
	return min;
}

void Span::addMoreNumber(std::vector <int> ::iterator itStart, std::vector <int> ::iterator itEnd)
{
	int	size = std::distance(itStart, itEnd);
	if (_v.size() + size > _n)
		throw std::overflow_error("Container is too small to add all numbers");
	while (itStart != itEnd)
	{
		addNumber(*itStart);
		itStart++;
	}
}