/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 03:29:55 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/13 01:38:49 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) { }

ScalarConverter::ScalarConverter(ScalarConverter &src) { (void)src; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter &src)
{
	(void)src;
	return *this;
}

ScalarConverter::~ScalarConverter(void) { }

void ScalarConverter::convert(std::string s)
{
	switch (get_literal_type(s))
	{
		case INT_LIT:
			print_int_literal(s);
			break;
		case FLT_LIT:
			print_flt_literal(s);
			break;
		case DBL_LIT:
			print_dbl_literal(s);
			break;
		case NAN_LIT:
			print_nan_literal(s);
			break;
		case P_INF_LIT:
			print_p_inf_literal(s);
			break;
		case N_INF_LIT:
			print_n_inf_literal(s);
			break;
		case CHR_LIT:
			print_chr_literal(s);
			break;
		default:
			print_non_literal(s);
	}
}
