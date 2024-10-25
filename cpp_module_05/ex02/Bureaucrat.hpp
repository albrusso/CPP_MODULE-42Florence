/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:38:19 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/22 13:05:38 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int	_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat const &operator=(const Bureaucrat& b);
		~Bureaucrat(void);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual char const *what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual char const *what(void) const throw();
		};

		std::string getName(void) const;
		int getGrade(void) const;

		void up(void);
		void down(void);
		void signForm(AForm &af);
		void executeForm(AForm const &form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif