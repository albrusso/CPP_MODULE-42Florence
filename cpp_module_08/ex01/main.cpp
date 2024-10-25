/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:42:50 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/25 15:13:21 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	try
	{
		Span s(10);
		std::vector<int> v;
		v.push_back(1);
		v.push_back(9);
		v.push_back(100);
		s.addMoreNumber(v.begin(), v.end());
		std::cout << "Shortest Span: " << s.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << s.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}