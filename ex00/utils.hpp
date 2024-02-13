/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:51:55 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/12 03:20:31 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <iostream>
# include <sstream>
#include <limits>

typedef enum e_lit_type
{
	UNK_LIT,
	NON_LIT,
	CHR_LIT,
	INT_LIT,
	FLT_LIT,
	DBL_LIT,
	P_INF_LIT,
	N_INF_LIT,
	NAN_LIT



} t_lit_type;

// cmp_utils.cpp
bool is_printable(char c);
bool is_digit(char c);
char to_lower(char c);
void to_lower(std::string &s);
t_lit_type check_nan_inf(std::string lower_s);
t_lit_type process_decimal(std::string &lower_s, size_t next_pos);
t_lit_type process_exponent(std::string &lower_s, size_t next_pos);
t_lit_type get_literal_type(std::string &s);

// print_utils.cpp
void print_int_literal(std::string &str);
void print_flt_literal(std::string &str);
void print_dbl_literal(std::string &str);
void print_chr_literal(std::string &str);
void print_p_inf_literal(std::string &str);
void print_n_inf_literal(std::string &str);
void print_nan_literal(std::string &str);
void print_non_literal(std::string &str);

#endif
