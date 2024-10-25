/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:19:33 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/24 13:59:14 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main(void)
{
	ShrubberyCreationForm shrubbery("Home");
	RobotomyRequestForm robotomy("Smart Contract");
	PresidentialPardonForm presidential("act1");
	Bureaucrat a("Aldo", 150);
	Bureaucrat d("Duccio", 120);
	Bureaucrat p("Pippo", 3);
	{
		try
		{
			std::cout << a << std::endl;
			std::cout << d << std::endl;
			std::cout << p << std::endl;
			std::cout << shrubbery << std::endl;
			a.executeForm(shrubbery);
			a.executeForm(robotomy);
			a.executeForm(presidential);
			d.executeForm(shrubbery);
			d.executeForm(robotomy);
			d.executeForm(presidential);
			p.executeForm(shrubbery);
			p.executeForm(robotomy);
			p.executeForm(presidential);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			shrubbery.beSigned(p);
			robotomy.beSigned(p);
			presidential.beSigned(p);
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << presidential << std::endl;
			a.executeForm(shrubbery);
			a.executeForm(robotomy);
			a.executeForm(presidential);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			p.executeForm(shrubbery);
			p.executeForm(robotomy);
			p.executeForm(presidential);

		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}