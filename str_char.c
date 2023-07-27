#include "main.h"
/**
 * print_ch - prints character
 * @args: character argument
 * Return: number of characters
 */


int print_ch(va_list args)
{
	int c;

	c = va_arg(args, int);
	return (_putchar(c));
}

/**
 * print_str - prints a string
 * @args: string  argument
 * Return: number of characters
 */


int print_str(va_list args)
{
	int i, count = 0;
	char *str;

	i = 0;
	str = va_arg(args, char*);
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
		count++;
	}
	return (count);
}
/**
 * print_percent - pass the percent sign
 * @args: the list of arguments
 * Return: return the percent sign
 */
int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}
