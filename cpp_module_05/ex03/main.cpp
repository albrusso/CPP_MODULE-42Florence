/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 15:19:33 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/24 14:29:15 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern intern;
	Bureaucrat p("Pippo", 1);
	AForm* form;

	form = intern.makeForm("ShrubberyCreationForm", "home");
	form->beSigned(p);
	p.executeForm(*form);
	delete form;
	form = intern.makeForm("RobotomyRequestForm", "robot");
	form->beSigned(p);
	p.executeForm(*form);
	delete form;
	form = intern.makeForm("PresidentialPardonForm", "president");
	form->beSigned(p);
	p.executeForm(*form);
	delete form;
	form = intern.makeForm("UnknownForm", "unknown");
	delete form;
	return 0;
}