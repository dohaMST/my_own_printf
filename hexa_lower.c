#include "main.h"

/**
 * lower_hex - function that writes signed hexadecimal integer
 * @args: variadic arguments
 * Return: the number of characters printed
 */
int lower_hex(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int x = n, wc = 0;
	int a, i;
	char c, *txt;

	if (n < 2)
	{
		c = '0' + n;
		write(STDOUT_FILENO, &c, 1);
		return (1);
	}

	while (x)
	{
		x /= 16;
		wc++;
	}
	txt  = malloc(sizeof(char) * (wc + 1));
	if (!txt)
		return (0);
	for (i = wc - 1; i >= 0; i--, n /= 16)
	{
		a = n % 16;
		txt[i] = (a > 9) ? (a - 10) + 'a' : a + '0';
	}

	txt[wc] = '\0';
	wc = write(STDOUT_FILENO, txt, wc);
	free(txt);

	return (wc);
}
