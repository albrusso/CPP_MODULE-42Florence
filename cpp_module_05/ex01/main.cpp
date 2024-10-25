/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:19:33 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/24 13:50:09 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	{
		try
		{
			Form a1("act 1", 0, 5);
			std::cout << a1 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}

	std::cout << std::endl;
	{
		try
		{
			Bureaucrat a("Aldo", 15);
			Form a2("Act 2", 20, 45);
			std::cout << a << std::endl;
			std::cout << a2 << std::endl;
			a.signForm(a2);
			std::cout << a2 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try
		{
			Bureaucrat d("Duccio", 35);
			Form a3("act 3", 20, 45);
			std::cout << d << std::endl;
			std::cout << a3 << std::endl;
			d.signForm(a3);
			std::cout << a3 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}