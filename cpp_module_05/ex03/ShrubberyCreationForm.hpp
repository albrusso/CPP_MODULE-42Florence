/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:37:09 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/22 14:03:40 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string _target);
	ShrubberyCreationForm(ShrubberyCreationForm& copy);
	ShrubberyCreationForm const	&operator=(ShrubberyCreationForm const &other);
	~ShrubberyCreationForm(void);

	void exe(Bureaucrat const &b) const;
};

std::ostream &operator<<(std::ostream &os, ShrubberyCreationForm &other);
