#include "main.h"

/**
 * handle_unsigned - a function that print an unsigned number
 * @args: the list of arguments
 * Return: an int hhh
 */

int handle_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int i = 0, j, writeCount = 0;
	int buff[size_of_buff];

	if (n == 0)
		return (_putchar('0'));
	while (n != 0)
	{
		buff[i++] = (n % 10) + '0';
		n = n / 10;
	}
	for (j = i - 1; j >= 0; j--)
		writeCount += _putchar(buff[j]);
	return (writeCount);
}
