#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * print_bin - convert to binary
 * @arg_list: va_list containing the number in decimal
 * Return: number of characters printed
 */
int print_bin(va_list arg_list)
{
	unsigned int len = 0, pow_two = 1, j, digit, num, num_copy;
	int count = 0;

	num = va_arg(arg_list, unsigned int);
	if (num != 0)
	{
		num_copy = num;
		while (num_copy != 0)
		{
			num_copy /= 2;
			len++;
		}
		for (j = 1; j <= len - 1; j++)
			pow_two *= 2;
		for (j = 1; j <= len; j++)
		{
			digit = num / pow_two;
			_putchar(digit + '0');
			count++;
			num -= digit * pow_two;
			pow_two /= 2;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}

