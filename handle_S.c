#include "main.h"

/**
 * handle_S - a function express %S
 * @args: the list of arguments
 * Return: number of char we printed
 */
int handle_S(va_list args)
{
	char *str, c, *txt;
	int x = 0, j, i = 0, wc = 2, a;
	unsigned int n;

	str = va_arg(args, char*);
	if (!str)
	{
		str = "(null)";
		write(STDOUT_FILENO, str, x = strlen(str));
		return (x);
	}
	while (str[i] != '\0')
	{
		n = (unsigned int)str[i];
		txt  = malloc(sizeof(char) * (wc + 1));
		if (!txt)
			return (-1);
		for (j = wc - 1; j != -1; j--)
		{
			a = n % 16;
			c = (a > 9) ? (a - 10) + 'A' : a + '0';
			txt[j] = c;
			n = n / 16;
		}
		txt[wc] = '\0';
		if ((str[i] >= 0 && str[i] < 32) || (str[i] >= 127))
			x +=  write(STDOUT_FILENO, "\\x", 2) + write(STDOUT_FILENO, txt, 2);
		else
		{
			write(STDOUT_FILENO, &str[i], 1);
			x++;
		}
		free(txt);
		i++;
	}
	return (x);
}
