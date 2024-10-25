/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:51:26 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/24 14:06:08 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm::AForm("ShrubberyCreationForm", 145, 137), _target("Blank")
{
	std::cout << "Default ShrubberyCreationForm costructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :  AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm costructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& copy) : AForm::AForm(copy), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm copy costructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm  destuctor called" << std::endl;
}

ShrubberyCreationForm const	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	this->_target = other._target;
	return (*this);
}

void ShrubberyCreationForm::exe(Bureaucrat const &b) const
{
	std::ofstream fd;
	std::string name;
	
	(void)b;
	name = this->_target + "_shrubbery";
	fd.open(name.c_str());
	if (fd.fail())
	{
		std::cout << "Could not open " << name << std::endl;
		return ;
	}
	fd << "       ccee88oo\n  C8O8O8Q8PoOb o8oo\n dOB69QO8PdUOpugoO9bD\nCgggbU8OU qOp qOdoUOdcb\n     6OuU  /p u gcoUodpP\n        \\\\\\//  /douUP\n          \\\\\\////\n            |||/\\\n            |||\\/\n            |||||\n      .....//||||\\....\n";
	fd.close();
}

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm &f)
{
	return os << "Name: " << f.getName() << " , signed: " << f.getSigned() << ", sign grade: " << f.getSignGrade() << ", exec grade: " << f.getExecGrade();
}