/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_utils.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:06:54 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/13 18:09:47 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cast_utils.hpp"

Base *generate(void)
{
	static bool seeded = false;
	int random;

	if (!seeded)
	{
		std::srand(time(NULL));
		seeded = true;
	}

	random = std::rand() % 3;

	if (random == 0)
		return new A;
	if (random == 1)
		return new B;
	return new C;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C";
	else
		std::cout << "Type not recognized";
}

void identify(Base& p)
{
	try
	{
		A &tmp = dynamic_cast<A&>(p);
		(void)tmp;
		std::cout << "A";
	}
	catch (std::exception &)
	{
		try
		{
			B &tmp = dynamic_cast<B&>(p);
			(void)tmp;
			std::cout << "B";
		}
		catch (std::exception &)
		{
			try
			{
				C &tmp = dynamic_cast<C&>(p);
				(void)tmp;
				std::cout << "C";
			}
			catch (std::exception &)
			{
				std::cout << "Type not recognized";
			}
		}
	}
}
