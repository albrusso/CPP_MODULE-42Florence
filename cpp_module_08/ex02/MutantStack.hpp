/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:38:33 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/25 14:43:51 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack <T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &copy);
		MutantStack &operator=(const MutantStack &ms);
		~MutantStack(void);

		typedef typename std::stack <T> ::container_type::iterator it;
		typedef typename std::stack <T> ::container_type::const_iterator cit;
		typedef typename std::stack <T> ::container_type::reverse_iterator rit;
		typedef typename std::stack <T> ::container_type::const_reverse_iterator crit;

		it begin(void);
		it end(void);
		cit cbegin(void);
		cit cend(void);
		rit rbegin(void);
		rit rend(void);
		crit crbegin(void);
		crit crend(void);
};

#include "MutantStack.tpp"

#endif