/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:53:21 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/25 13:21:11 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Insert atleast 1 number" << std::endl;
		return 1;
	}
	try
	{
		std::vector <int> v;
		for (int i = 1; i < ac; i++)
		{
			if (std::atoi(av[i]) <= 0)
			{
				if ((av[i][0] == '0' && av[i][1]) || av[i][0] != '0')
					throw std::invalid_argument("Args must be positive number");
			}
			v.push_back(std::atoi(av[i]));
		}
		PmergeMe pm(v);
		pm.sortAndPrint();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return 1;
	}
	return 0;
}
