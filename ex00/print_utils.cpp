/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:51:38 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/27 21:28:05 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void print_chr_literal(std::string &str)
{
	char c = str[0];
	int i = static_cast<int>(c);

	if (is_printable(c))
		std::cout << "char:   '" << c << "'";
	else
		std::cout << "char:   Non displayable";

	std::cout << "\nint:    " << i;
	std::cout << "\nfloat:  " << static_cast<float>(i) << 'f';
	std::cout << "\ndouble: " << static_cast<double>(i) << std::endl;
}

void print_nan_literal(std::string &str)
{
	(void)str;

	std::cout << "char:   impossible";
	std::cout << "\nint:    impossible";
	std::cout << "\nfloat:  nanf";
	std::cout << "\ndouble: nan" << std::endl;
}

void print_p_inf_literal(std::string &str)
{
	(void)str;

	std::cout << "char:   impossible";
	std::cout << "\nint:    impossible";
	std::cout << "\nfloat:  +inff";
	std::cout << "\ndouble: +inf" << std::endl;
}

void print_n_inf_literal(std::string &str)
{
	(void)str;

	std::cout << "char:   impossible";
	std::cout << "\nint:    impossible";
	std::cout << "\nfloat:  -inff";
	std::cout << "\ndouble: -inf" << std::endl;
}

void print_int_literal(std::string &str)
{
	std::stringstream ss(str);
	int i;
	char c;

	ss >> i;

	if (ss.fail())
	{
		std::cout << "char:   impossible";
		std::cout << "\nint:    impossible";
		std::cout << "\nfloat:  impossible";
		std::cout << "\ndouble: impossible" << std::endl;
		return;
	}

	if (i >= std::numeric_limits<char>::min() &&
		i < std::numeric_limits<char>::max())
	{
		c = static_cast<char>(i);
		if (is_printable(c))
			std::cout << "char:   '" << c << "'";
		else
			std::cout << "char:   Non displayable";
	}
	else
		std::cout << "char:   impossible";

	std::cout << "\nint:    " << i;
	std::cout << "\nfloat:  " << static_cast<float>(i) << 'f';
	std::cout << "\ndouble: " << static_cast<double>(i) << std::endl;
}

void print_flt_literal(std::string &str)
{
	std::stringstream ss(str);
	float f;
	int i;
	char c;
	int p = std::numeric_limits<long double>::digits10 + 1;

	ss >> std::setprecision(p) >> f;

	if (ss.fail())
	{
		std::cout << "char:   impossible";
		std::cout << "\nint:    impossible";
		std::cout << "\nfloat:  impossible";

		std::cout << "\ndouble: impossible" << std::endl;
		return;
	}

	if (f >= std::numeric_limits<int>::min() &&
			f <= std::numeric_limits<int>::max() - 0.5)
	{
		i = static_cast<int>(f);

		if (i < std::numeric_limits<char>::min())
			std::cout << "char:   impossible";
		else if (i > std::numeric_limits<char>::max())
			std::cout << "char:   impossible";
		else
		{
			c = static_cast<char>(i);

			if (is_printable(c))
				std::cout << "char:   '" << c << "'";
			else
				std::cout << "char:   Non displayable";
		}
		std::cout << "\nint:    " << i;
	}
	else
	{
		std::cout << "char:   impossible";
		std::cout << "\nint:    impossible";
	}

	std::cout << "\nfloat:  " << f << 'f';
	std::cout << "\ndouble: " << static_cast<double>(f) << std::endl;
}

void print_dbl_literal(std::string &str)
{
	std::stringstream ss(str);
	double d;
	int i;
	char c;
	int p = std::numeric_limits<long double>::digits10 + 1;

	ss >> std::setprecision(p) >> d;

	if (ss.fail())
	{
		std::cout << "char:   impossible";
		std::cout << "\nint:    impossible";
		std::cout << "\nfloat:  impossible";
		std::cout << "\ndouble: impossible" << std::endl;

		return;
	}

	if (d >= std::numeric_limits<int>::min() &&
			d <= std::numeric_limits<int>::max())
	{
		i = static_cast<int>(d);

		if (i < std::numeric_limits<char>::min())
			std::cout << "char:   impossible";
		else if (i > std::numeric_limits<char>::max())
			std::cout << "char:   impossible";
		else
		{
			c = static_cast<char>(i);
			if (is_printable(c))
				std::cout << "char:   '" << c << "'";
			else
				std::cout << "char:   Non displayable";
		}
		std::cout << "\nint:    " << i;
	}
	else
	{
		std::cout << "char:   impossible";
		std::cout << "\nint:    impossible";
	}

	if (d >= -std::numeric_limits<float>::max() &&
		d <= std::numeric_limits<float>::max())
		std::cout << "\nfloat:  " << static_cast<float>(d) << 'f';
	else
		std::cout << "\nfloat:  impossible";

	std::cout << "\ndouble: " << d << std::endl;
}

void print_non_literal(std::string &str)
{
	(void)str;

	std::cout << "char:   impossible";
	std::cout << "\nint:    impossible";
	std::cout << "\nfloat:  impossible";
	std::cout << "\ndouble: impossible" << std::endl;
}
