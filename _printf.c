#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stddef.h>
#include <unistd.h>

/**
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
 */


int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list list;
	int (*m)(va_list);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

		va_start(list, format);

		for (i = 0; format != NULL && format[i] != '\0'; i++)
		{
			if (format[i] == '%')
			{
				m = func_select(format[i + 1]);
				if (m)
					count += m(list);
				else
				{
					 count += _putchar(format[i]);
					 count += _putchar(format[i + 1]);
				}
				 i++;
			}
			else
				 count += _putchar(format[i]);
		}
		va_end(list);
		return (count);
}
