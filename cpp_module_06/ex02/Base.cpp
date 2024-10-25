/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:35:15 by albrusso          #+#    #+#             */
/*   Updated: 2024/07/24 14:41:45 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(void)
{
	std::cout << "Base destructor called" << std::endl;
}

Base * generate(void)
{
	std::srand(static_cast <unsigned int> (std::time(NULL)));
	int n = std::rand() % 3;
	switch (n)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast <A*> (p))
		std::cout << "p point at type A" << std::endl;
	else if (dynamic_cast <B*> (p))
		std::cout << "p point at type B" << std::endl;
	else if (dynamic_cast <C*> (p))
		std::cout << "p point at type C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "p is a reference to type A" << std::endl;
		return;
	}
	catch (...)
	{
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "p is a reference to type B" << std::endl;
		return;
	} 
	catch (...)
	{
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "p is a reference to type C" << std::endl;
		return;
	} catch (...)
	{
		std::cout << "p is of unknown type" << std::endl;
	}
}