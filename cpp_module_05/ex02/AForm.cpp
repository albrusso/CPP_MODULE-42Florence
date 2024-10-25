/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:33:44 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/22 13:11:29 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Blank"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "AForm default costructor called" << std::endl;
}

AForm::AForm(std::string name, const int signGrade, const int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (this->_signGrade < 1 || this->_execGrade < 1)
		throw(AForm::GradeTooHighException());
	if (this->_signGrade > 150 || this->_execGrade > 150)
		throw(AForm::GradeTooLowException());
	std::cout << "AForm costructor called" << std::endl;
}

AForm::AForm(const AForm& copy) : _name(copy._name), _signed(copy._signed), _signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
	*this = copy;
	std::cout << "AForm copy costructor called" << std::endl;
}

AForm const &AForm::operator=(const AForm& af)
{
	this->_signed = af._signed;
	return *this;
	std::cout << "AForm overload operator '=' called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return "grade too high";
}
const char *AForm::GradeTooLowException::what(void) const throw()
{
	return "grade too low";
}

char const	*AForm::FormNotSignedException::what(void) const throw()
{
	return "Form is not signed";
}

std::string AForm::getName(void) const
{
	return this->_name;
}

bool AForm::getSigned(void) const
{
	return this->_signed;
}

int AForm::getSignGrade(void) const
{
	return this->_signGrade;
}

int AForm::getExecGrade(void) const
{
	return this->_execGrade;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->_signGrade)
		throw (AForm::GradeTooLowException());
	else
		this->_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_signed)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->_signGrade)
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout << executor.getName() << " executes form: " << this->_name << std::endl;
		this->exe(executor);
	}
}

std::ostream &operator<<(std::ostream &os, const AForm &af)
{
	os << "Name: " << af.getName() << ", signed: " << af.getSigned() << ", sign grade: " << af.getSignGrade() << ", exec grade: " << af.getExecGrade();
	return os;
}