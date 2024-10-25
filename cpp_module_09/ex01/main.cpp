/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:58:35 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/24 15:39:01 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Try: npm [expression]" << std::endl;
		return 1;
	}
	std::string exp(av[1]);
	RPN rpn(exp);
	try
	{
		int res = rpn.execute();
		std::cout << res << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return 1;
	}
	return 0;
}