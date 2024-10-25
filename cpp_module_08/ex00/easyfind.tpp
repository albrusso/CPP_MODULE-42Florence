/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:14:28 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/24 14:21:04 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <algorithm>

const char* notFoundException::what() const throw()
{
	return "Integer not found";
}

template <typename T>
typename T::iterator easyfind(T &c, int i)
{
	typename T::iterator it = std::find(c.begin(), c.end(), i);
	if (it == c.end())
	{
		throw(notFoundException());
	}
	return it;
}