#include "main.h"

#include <stdlib.h>
#include <stdio.h>
/**
 * p_handler - a function that help to print pointer
 * @n: the number we gonna use
 * @wc: a parameter number 1
 * Return: apointer to char
*/

char *p_handler(int wc, unsigned long n)
{
	char *buff = malloc(sizeof(char) * (wc + 1));
	int a;
	char *ptr;

	if (!buff)
		return (NULL);

	buff[wc] = '\0';

	ptr = buff + wc - 1;

	while (n > 0)
	{
		a = n % 16;
		*ptr-- = (a > 9) ? ('a' + (a - 10)) : ('0' + a);
		n /= 16;
	}

	return (buff);
}


/**
 * handle_pointer - a function that writes signed hexadecimal integer
 * @args:variadic arguments
 * Return:the number of characters printed
*/
int handle_pointer(va_list args)
{
	unsigned long n = (unsigned long) va_arg(args, void *);
	char *buff;
	unsigned long x;
	int wc = 0;

	if (n == 0)
		return (write(STDOUT_FILENO, "(nil)", 5));

	for (x = n; x != 0; x /= 16)
		wc++;

	buff = p_handler(wc, n);

	if (buff == NULL)
		return (0);

	write(STDOUT_FILENO, "0x", 2);
	write(STDOUT_FILENO, buff, wc);

	free(buff);
	return (wc + 2);
}
