/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 01:03:02 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/13 03:52:26 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(void)
{
	std::stringstream ss("");
	long long int ll;
	int p = std::numeric_limits<long double>::digits10 + 1;

	std::cout << "Test char literals:\n\n";

	std::cout << "-> Displayable chars:";
	std::cout << "\n--> Character 'a':\n";
	ScalarConverter::convert("a");
	std::cout << "\n--> Character ' ' (space):\n";
	ScalarConverter::convert(" ");
	std::cout << "\n--> Character '~' (tilde):\n";
	ScalarConverter::convert("~");
	std::cout << "\n" << std::endl;

	std::cout << "-> Non-displayable chars:\n";
	std::cout << "\n--> Character 0x7F (one after '~'):\n";
	ScalarConverter::convert("\x7F");
	std::cout << "\n--> Character 0x7F (one before ' '):\n";
	ScalarConverter::convert("\x1F");
	std::cout << "\n--> Character 0x0A (Enter):\n";
	ScalarConverter::convert("\x0A");
	std::cout << "\n" << std::endl;

	std::cout << "-> Integers:\n";
	std::cout << "\n--> 0:\n";
	ScalarConverter::convert("0");

	ss << std::setprecision(p) << std::numeric_limits<int>::max();
	std::cout << "\n--> Maximum integer value: " << std::fixed
		<< std::setprecision(1) << std::numeric_limits<int>::max() << "\n";
	ScalarConverter::convert(ss.str());

	ss.str("");
    ss.clear();
	ss << std::numeric_limits<int>::min();
	std::cout << "\n--> Minimum integer value: "
		<< std::numeric_limits<int>::min() << "\n";
	ScalarConverter::convert(ss.str());

	ll = static_cast<long long int>(std::numeric_limits<int>::max()) + 1ll;
	ss.str("");
	ss.clear();
	ss << ll;
	std::cout << "\n--> Maximum integer value + 1: " << ll << "\n";
	ScalarConverter::convert(ss.str());

	ll = static_cast<long long int>(std::numeric_limits<int>::min()) - 1ll;
	ss.str("");
	ss.clear();
	ss << ll;
	std::cout << "\n--> Minimum integer value - 1: " << ll << "\n";
	ScalarConverter::convert(ss.str());

	std::cout << "\n" << std::endl;

	std::cout << "-> Floats:\n";
	std::cout << "\n--> 0f:\n";
	ScalarConverter::convert("0f");

	ss.str("");
	ss.clear();
	ss << std::numeric_limits<float>::max() << 'f';
	std::cout << "\n--> Largest positive float value: "
		<< std::numeric_limits<float>::max() << "f\n";
	ScalarConverter::convert(ss.str());

	ss.str("");
	ss.clear();
	ss << (static_cast<double>(std::numeric_limits<float>::max()) + 0.1e+38)
		<< 'f';
	std::cout << "\n--> Largest positive float value + 0.1e+38: "
		<< (static_cast<double>(std::numeric_limits<float>::max()) + 0.1e+38)
		<< "f\n";
	ScalarConverter::convert(ss.str());

	ss.str("");
	ss.clear();
	ss << std::numeric_limits<float>::min() << 'f';
	std::cout << "\n--> Smallest positive float value: "
		<< std::numeric_limits<float>::min() << "f\n";
	ScalarConverter::convert(ss.str());

	ss.str("");
	ss.clear();
	ss << -std::numeric_limits<float>::max() << 'f';
	std::cout << "\n--> Largest negative float value: "
		<< -std::numeric_limits<float>::max() << "f\n";
	ScalarConverter::convert(ss.str());

	ss.str("");
	ss.clear();
	ss << (static_cast<double>(-std::numeric_limits<float>::max()) - 0.1e+38)
		<< 'f';
	std::cout << "\n--> Largest negative float value - 0.1e+38: "
		<< (static_cast<double>(-std::numeric_limits<float>::max()) - 0.1e+38)
		<< "f\n";
	ScalarConverter::convert(ss.str());

	ss.str("");
	ss.clear();
	ss << -std::numeric_limits<float>::min();
	std::cout << "\n--> Smallest negative float value: "
		<< -std::numeric_limits<float>::min() << "\n";
	ScalarConverter::convert(ss.str());

	std::cout << "\n" << std::endl;

	std::cout << "-> Floats (special literals):\n";
	std::cout << "\n--> No digit after decimal point: 1.f:\n";
	ScalarConverter::convert("1.f");
	std::cout << "\n--> No digit before decimal point: .1f:\n";
	ScalarConverter::convert(".1f");
	std::cout << "\n--> No digit before and after decimal point (invalid):"
		<< ".f:\n";
	ScalarConverter::convert(".f");
	std::cout << "\n--> Value with exponent: 1.5e10f:\n";
	ScalarConverter::convert("1.5e10f");
	std::cout << "\n--> No digit after decimal point with exponent: 1.e10f:\n";
	ScalarConverter::convert("1.e10f");
	std::cout << "\n--> No digit before decimal point with exponent: "
		<< ".1e10f\n";
	ScalarConverter::convert(".1e10f");
	std::cout << "\n--> No digit before and after decimal point "
		<< "with exponent (invalid): .e10f:\n";
	ScalarConverter::convert(".e10f");
	std::cout << "\n--> Value with just the exponent (invalid): e10f:\n";
	ScalarConverter::convert("e10f");
	std::cout << "\n--> Value with decimal point after exponent: 1.5e10.1f:\n";
	ScalarConverter::convert("1.5e10.1f");
	std::cout << "\n--> Not a number: nanf:\n";
	ScalarConverter::convert("nanf");
	std::cout << "\n--> Not a number with uppercase: NaNf:\n";
	ScalarConverter::convert("NaNf");
	std::cout << "\n--> Positive infinite (no sign): inff:\n";
	ScalarConverter::convert("inff");
	std::cout << "\n--> Positive infinite with uppercase (no sign): Inff:\n";
	ScalarConverter::convert("Inff");
	std::cout << "\n--> Positive infinite (with sign): +inff:\n";
	ScalarConverter::convert("+inff");
	std::cout << "\n--> Positive infinite with uppercase (with sign): +Inff:\n";
	ScalarConverter::convert("+Inff");
	std::cout << "\n--> Negative infinite: -inff:\n";
	ScalarConverter::convert("-inff");
	std::cout << "\n--> Negative infinite with uppercase: -Inff:\n";
	ScalarConverter::convert("-Inff");

	std::cout << "\n" << std::endl;

	std::cout << "-> Doubles:\n";
	std::cout << "\n--> 0.0:\n";
	ScalarConverter::convert("0f");

	ss.str("");
	ss.clear();
	ss << std::numeric_limits<double>::max();
	std::cout << "\n--> Largest positive double value: "
		<< std::numeric_limits<double>::max() << "\n";
	ScalarConverter::convert(ss.str());

	std::cout << "\n--> Largest positive double value + 0.1e308: 1.9e308\n";
	ScalarConverter::convert("1.9e308");

	ss.str("");
	ss.clear();
	ss << std::numeric_limits<double>::min();
	std::cout << "\n--> Smallest positive double value: "
		<< std::numeric_limits<double>::min() << "\n";
	ScalarConverter::convert(ss.str());

	ss.str("");
	ss.clear();
	ss << -std::numeric_limits<double>::max();
	std::cout << "\n--> Largest negative double value: "
		<< -std::numeric_limits<double>::max() << "\n";
	ScalarConverter::convert(ss.str());

	std::cout << "\n--> Largest negative double value + 0.1e308: -1.9e308\n";
	ScalarConverter::convert("-1.9e308");

	ss.str("");
	ss.clear();
	ss << -std::numeric_limits<double>::min();
	std::cout << "\n--> Smallest negative double value: "
		<< -std::numeric_limits<double>::min() << "\n";
	ScalarConverter::convert(ss.str());

	std::cout << "\n--> Smallest negative double value - 0.1e308: -1.9e308\n";
	ScalarConverter::convert("-1.9e308");

	std::cout << "\n" << std::endl;

	std::cout << "-> Doubles (special literals):\n";
	std::cout << "\n--> No digit after decimal point: 1.:\n";
	ScalarConverter::convert("1.");
	std::cout << "\n--> No digit before decimal point: .1:\n";
	ScalarConverter::convert(".1");
	std::cout << "\n--> No digit before and after decimal point (invalid):"
		<< ".:\n";
	ScalarConverter::convert(".");
	std::cout << "\n--> Value with exponent: 1.5e10:\n";
	ScalarConverter::convert("1.5e10");
	std::cout << "\n--> No digit after decimal point with exponent: 1.e10:\n";
	ScalarConverter::convert("1.e10");
	std::cout << "\n--> No digit before decimal point with exponent: "
		<< ".1e10:\n";
	ScalarConverter::convert(".1e10");
	std::cout << "\n--> No digit before and after decimal point "
		<< "with exponent (invalid): .e10:\n";
	ScalarConverter::convert(".e10");
	std::cout << "\n--> Value with just the exponent (invalid): e10:\n";
	ScalarConverter::convert("e10");
	std::cout << "\n--> Value with decimal point after exponent: 1.5e10.1:\n";
	ScalarConverter::convert("1.5e10.1");
	std::cout << "\n--> Not a number: nan:\n";
	ScalarConverter::convert("nan");
	std::cout << "\n--> Not a number with uppercase: NaN:\n";
	ScalarConverter::convert("NaN");
	std::cout << "\n--> Positive infinite (no sign): inf:\n";
	ScalarConverter::convert("inf");
	std::cout << "\n--> Positive infinite with uppercase (no sign): Inf:\n";
	ScalarConverter::convert("Inf");
	std::cout << "\n--> Positive infinite (with sign): +inf:\n";
	ScalarConverter::convert("+inf");
	std::cout << "\n--> Positive infinite with uppercase (with sign): +Inf:\n";
	ScalarConverter::convert("+Inf");
	std::cout << "\n--> Negative infinite: -inf:\n";
	ScalarConverter::convert("-inf");
	std::cout << "\n--> Negative infinite with uppercase: -Inf:\n";
	ScalarConverter::convert("-Inf");

	std::cout << "\n" << std::endl;

	std::cout << "-> Non-literals:\n";
	std::cout << "\n--> Empty string: \"\":\n";
	ScalarConverter::convert("");
	std::cout << "\n--> String with length 2 with non-digits: \"ab\":\n";
	ScalarConverter::convert("ab");
	std::cout << "\n--> String with random text: \"banana\":\n";
	ScalarConverter::convert("banana");
	std::cout << "\n--> Invalid integer: 1d:\n";
	ScalarConverter::convert("1d");
	std::cout << "\n--> Invalid float: 1fd:\n";
	ScalarConverter::convert("1fd");
	std::cout << "\n--> Invalid float with exponent: 1e10fd:\n";
	ScalarConverter::convert("1e10fd");
	std::cout << "\n--> Invalid float with empty exponent: 1efd:\n";
	ScalarConverter::convert("1efd");
	std::cout << "\n--> Invalid double with digit after decimal: 1.0d:\n";
	ScalarConverter::convert("1.0d");
	std::cout << "\n--> Invalid double without digit after decimal: 1.d:\n";
	ScalarConverter::convert("1.d");
	std::cout << "\n--> Invalid double without digit before decimal: .1d:\n";
	ScalarConverter::convert(".1d");
	std::cout << "\n--> Invalid double with exponent: 0.1e10d:\n";
	ScalarConverter::convert("0.1e10d");

	std::cout << std::endl;
}
