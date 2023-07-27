#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

/**
 * handle_octal - a function that writes signed octal integer
 * @args:variadic arguments
 * Return:the number of characters printed
 */
int handle_octal(va_list args)
{
	unsigned int a, wc = 0, n = va_arg(args, unsigned int);
	char x, *txt;
	int i;

	if (n == 1 || n == 0)
	{
		x = '0' + n;
		write(STDOUT_FILENO, &x, 1);
		return (1);
	}
	for (a = n; a != 0; a /= 8)
		wc++;
	txt = malloc(sizeof(char) * wc + 1);
	if (!txt)
		return (0);
	for (i = wc - 1; i >= 0; i--)
	{
		x = (n % 8) + '0';
		txt[i] = x;
		n /= 8;
	}
	txt[wc] = '\0';
	wc = write(STDOUT_FILENO, txt, wc);
	free(txt);
	return (wc);
}

