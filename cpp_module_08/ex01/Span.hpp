/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:43:15 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/25 14:48:04 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int _n;
		std::vector <int> _v;
	public:
		Span(void);
		Span(unsigned int n);
		Span (const Span &copy);
		Span &operator=(const Span &v);
		int operator[](int i);
		~Span(void);

		void addNumber(int num);
		int shortestSpan(void);
		int longestSpan(void);
		unsigned int getSize(void);
		void addMoreNumber(std::vector <int> ::iterator itStart, std::vector <int> ::iterator itEnd);
};

#endif