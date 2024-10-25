/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:50:43 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/24 13:48:08 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Blank"), _grade(150)
{
	std::cout << "Bureaucrat default costructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	this->_grade = grade;
	if (this->_grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	if (this->_grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	std::cout << "Bureaucrat costructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	*this = copy;
}

Bureaucrat const &Bureaucrat::operator=(const Bureaucrat &b)
{
	this->_grade = b._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "grade too high";
}
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "grade too low";
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::up(void)
{
	this->_grade--;
	if (this->_grade < 1)
		throw(Bureaucrat::GradeTooHighException());
}

void Bureaucrat::down(void)
{
	this->_grade++;
	if (this->_grade > 150)
		throw(Bureaucrat::GradeTooLowException());
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}