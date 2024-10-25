/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:20:38 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/24 13:49:02 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
	public:
		Form(void);
		Form(const std::string name, const int signGrade, const int signExec);
		Form(const Form &copy);
		Form const &operator=(const Form &f);
		~Form(void);

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
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool getSigned(void) const;

		void beSigned(Bureaucrat &b);
};

std::ostream& operator<<(std::ostream& os, const Form &f);

#endif