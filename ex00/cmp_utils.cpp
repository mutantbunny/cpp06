/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_utils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:54:41 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/13 01:40:01 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool is_printable(char c) { return (c > 31 && c < 127); }

bool is_digit(char c) { return (c >= '0' && c <= '9'); }

char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return c;
}

void to_lower(std::string &s)
{
	for (size_t i = 0; i < s.length(); ++i)
		s[i] = to_lower(s[i]);
}

t_lit_type check_nan_inf(std::string lower_s)
{
	const size_t s_len = lower_s.length();

	if (s_len == 3)
	{
		if (lower_s == "nan")
			return NAN_LIT;

		if (lower_s == "inf")
			return P_INF_LIT;
	}

	else if (s_len == 4)
	{
		if (lower_s == "-inf")
			return N_INF_LIT;

		if (lower_s == "inff" || lower_s == "+inf")
			return P_INF_LIT;
	}

	else if (s_len == 5)
	{
		if (lower_s == "-inff")
			return N_INF_LIT;

		if (lower_s == "+inff")
			return P_INF_LIT;
	}

	return UNK_LIT;
}

t_lit_type process_exponent(std::string &lower_s, size_t next_pos)
{
	size_t s_len = lower_s.length();

	if (next_pos >= s_len)
		return NON_LIT;

	char c = lower_s[next_pos];

	if (c == '+' || c == '-')
		++next_pos;

	for (size_t pos = next_pos; pos < s_len; ++pos)
	{
		c = lower_s[pos];

		if (!is_digit(c))
		{
			if (c == 'f' && pos == s_len - 1)
				return FLT_LIT;

			return NON_LIT;
		}
	}
	return DBL_LIT;
}

t_lit_type process_decimal(std::string &lower_s, size_t next_pos)
{
	char c;
	size_t s_len = lower_s.length();

	if (next_pos >= s_len)
		return NON_LIT;

	for (size_t pos = next_pos; pos < s_len; ++pos)
	{
		c = lower_s[pos];

		if (!is_digit(c))
		{
			if (c == 'e')
				return process_exponent(lower_s, pos + 1);

			if (c == 'f' && pos == s_len - 1)
				return FLT_LIT;

			return NON_LIT;
		}
	}

	return DBL_LIT;

}

t_lit_type get_literal_type(std::string &s)
{
	char c;
	size_t pos;
	const size_t s_len = s.length();
	t_lit_type lit_type;

	if (s_len == 0)
		return NON_LIT;

	c = s[0];

	if (s_len == 1)
	{
		if (is_digit(c))
			return INT_LIT;

		return CHR_LIT;
	}

	to_lower(s);
	lit_type = check_nan_inf(s);

	if (lit_type != UNK_LIT)
		return lit_type;

	pos = 0;

	if (c == '+' || c == '-')
	{
		if (!isdigit(s[1]) && s[1] != '.')
			return NON_LIT;
		++pos;
	}

	if (s[pos] == '.')
	{
		if (s_len == pos + 1 || !is_digit(s[pos + 1]))
			return NON_LIT;
	}

	for (; pos < s_len; ++pos)
	{
		c = s[pos];

		if (!is_digit(c))
		{
			if (c == '.')
				return process_decimal(s, pos + 1);

			if (c == 'e')
				return process_exponent(s, pos + 1);

			if (c == 'f' && pos == s_len - 1)
				return FLT_LIT;

			return NON_LIT;
		}
	}

	return INT_LIT;
}
