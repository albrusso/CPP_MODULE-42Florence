/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:47:12 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/22 13:05:00 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm::AForm("RobotomyRequestForm", 72, 45), _target("Blank")
{
	std::cout << "Default RobotomyRequestForm costructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm::AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm costructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm::AForm(copy), _target(copy._target)
{
	std::cout << "RobotomyRequestForm copy costructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm const	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	this->_target = other._target;
	std::cout << "RobotomyRequestForm overload operator '=' called" << std::endl;
	return (*this);
}

void	RobotomyRequestForm::exe(const Bureaucrat &b) const
{
	int	i;

	(void)b;
	srand((unsigned) time(NULL));
	i = rand() % 2;
	std::cout << "Making some drilling noises..." << std::endl;
	if (i)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " the robotomy failed" << std::endl;
}

std::ostream &operator<<(std::ostream &str, RobotomyRequestForm const &form)
{
	return (str << form.getName() << " form, signed: " << form.getSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}