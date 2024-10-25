/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:33:44 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/22 13:01:33 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Blank"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Form default costructor called" << std::endl;
}

Form::Form(std::string name, const int signGrade, const int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw(Form::GradeTooHighException());
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw(Form::GradeTooLowException());
	std::cout << "Form costructor called" << std::endl;
}

Form::Form(const Form& copy) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	*this = copy;
	std::cout << "Form copy costructor called" << std::endl;
}

Form const &Form::operator=(const Form& other)
{
	this->_signed = other._signed;
	return *this;
	std::cout << "Form overload operator '=' called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return "grade too high";
}
const char *Form::GradeTooLowException::what(void) const throw()
{
	return "grade too low";
}

std::string Form::getName(void) const
{
	return this->_name;
}

bool Form::getSigned(void) const
{
	return this->_signed;
}

int Form::getSignGrade(void) const
{
	return this->_signGrade;
}

int Form::getExecGrade(void) const
{
	return this->_execGrade;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_signGrade)
		throw (Form::GradeTooLowException());
	else
		this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Name: " << f.getName() << ", signed: " << f.getSigned() << ", sign grade: " << f.getSignGrade() << ", exec grade: " << f.getExecGrade();
	return os;
}