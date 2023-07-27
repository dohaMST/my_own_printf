#include "main.h"

/**
 * print_decimal1 - prints an integer
 * @lists: input string
 * Return: number of chars printed.
 */
int print_decimal1(va_list lists)
{
	int num;
	unsigned int num_copy, int_temp, i, j, negative;

	num = va_arg(lists, int);
	negative = 0;
	if (num < 0)
	{
		num_copy = num * -1;
		_putchar('-');
		negative = 1;
	}
	else
	{
		num_copy = num;
	}

	int_temp = num_copy;
	j = 1;

	while (int_temp > 9)
	{
		j *= 10;
		int_temp /= 10;
	}

	for (i = 0; j > 0; j /= 10, i++)
	{
		_putchar(((num_copy / j) % 10) + '0');
	}
	return (i + negative);
}
