/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:38:49 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/25 14:44:17 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack <T>::MutantStack(void)
{
	std::cout << "MutantStack default costructor called" << std::endl;
}

template <typename T>
MutantStack <T>::MutantStack(const MutantStack &copy)
{
	*this = copy;
	std::cout << "MutantStack copy costructor called" << std::endl;
}

template <typename T>
MutantStack <T> &MutantStack <T>::operator=(const MutantStack &ms)
{
	if (this != &ms)
		std::stack <T> ::operator=(ms);
	return *this;
}

template <typename T>
MutantStack <T>::~MutantStack(void)
{
	std::cout << "MutantStack destructor called" << std::endl;
}

template <typename T>
typename MutantStack <T> ::it MutantStack <T> :: begin(void)
{
	return this->c.begin();
}

template <typename T>
typename MutantStack <T> ::it MutantStack <T> :: end(void)
{
	return this->c.end();
}

template <typename T>
typename MutantStack <T> ::cit MutantStack <T> :: cbegin(void)
{
	return this->c.cbegin();
}

template <typename T>
typename MutantStack <T> ::cit MutantStack <T> :: cend(void)
{
	return this->c.cend();
}

template <typename T>
typename MutantStack <T> ::rit MutantStack <T> :: rbegin(void)
{
	return this->c.rbegin();
}

template <typename T>
typename MutantStack <T> ::rit MutantStack <T> :: rend(void)
{
	return this->c.rend();
}

template <typename T>
typename MutantStack <T> ::crit MutantStack <T> :: crbegin(void)
{
	return this->c.crbegin();
}

template <typename T>
typename MutantStack <T> ::crit MutantStack <T> :: crend(void)
{
	return this->c.crend();
}


