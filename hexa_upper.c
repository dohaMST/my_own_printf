#include "main.h"

/**
 * upper_heX- a function that print hexa
 * @args:variadic arguments
 * Return:the number of char we print
*/
int upper_heX(va_list args)
{
	unsigned int x, wc, n;
	int a, i;
	char c, *txt;

	n = va_arg(args, unsigned int);
	if (n == 1 || n == 0)
	{
		c = '0' + n;
		write(STDOUT_FILENO, &c, 1);
		return (1);
	}

	x = n;
	wc = 0;
	while (x != 0)
	{
		x = x / 16;
		wc++;
	}

	txt  = malloc(sizeof(char) * (wc + 1));
	if (!txt)
		return (0);
	for (i = wc - 1; i != -1; i--)
	{
		a = n % 16;

		if (a > 9)
			c = (a - 10) + 'A';
		else
			c = a + '0';
		txt[i] = c;
		n = n / 16;
	}
	txt[wc] = '\0';
	wc =  write(STDOUT_FILENO, txt, wc);
	free(txt);
	return (wc);
}
