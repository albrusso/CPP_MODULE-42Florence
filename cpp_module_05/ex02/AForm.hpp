/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:20:38 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/22 13:04:11 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
	public:
		AForm(void);
		AForm(const std::string name, const int signGrade, const int signExec);
		AForm(const AForm &copy);
		AForm const &operator=(const AForm &f);
		~AForm(void);

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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual char const *what(void) const throw();
		};
		std::string getName(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		bool getSigned(void) const;

		void beSigned(Bureaucrat &b);
		void execute(Bureaucrat const & executor) const;
		virtual void exe(Bureaucrat const &b) const = 0;

};

std::ostream& operator<<(std::ostream &os, const AForm &f);

#endif