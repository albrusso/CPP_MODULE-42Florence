/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:24:17 by albrusso          #+#    #+#             */
/*   Updated: 2024/03/04 15:31:06 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact book[8];
	int	i;
	int	full;
	int	replace;
public:
	PhoneBook(void);
	~PhoneBook(void);
	void	add(void);
	void	search(void);
	Contact	getContact(int n) const;
};
#endif