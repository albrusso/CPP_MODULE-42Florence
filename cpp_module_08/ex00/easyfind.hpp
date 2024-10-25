/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:13:56 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/25 14:01:52 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <exception>

class notFoundException : public std::exception
{
	public:
		const char* what() const throw();
};

template <typename T>
typename T::iterator easyfind(T &c, int i);

#include "easyfind.tpp"

#endif