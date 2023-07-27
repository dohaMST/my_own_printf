#include "main.h"
/**
 * func_select - selects the function based on the format
 * @format: format specifier character
 * Return: pointer to the appropriate printing function
 */
int (*func_select(char format))(va_list)
{
	switch (format)
	{
	case 'c':
		return (&print_ch);
	case 's':
		return (&print_str);
	case 'd':
		return (&print_decimal1);
	case 'i':
		return (&print_int);
	case '%':
		return (&print_percent);
	case 'b':
		return (&print_bin);
	case 'u':
		return (&handle_unsigned);
	case 'o':
		return (&handle_octal);
	case 'p':
		return (&handle_pointer);
	case 'x':
		return (&lower_hex);
	case 'X':
		return (&upper_heX);
	case 'r':
		return (&handle_rev);
	case 'R':
		return (&handle_rot);
	case 'S':
		return (&handle_S);
	default:
		return (NULL);
	}
}
