#include "main.h"

/**
 * handle_rot - a function the print a string in rot13
 * @args: the list of arguments
 * Return: an int
 */

int handle_rot(va_list args)
{
	char *txt;
	char *p;
	int wc = 0;
	char *old = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *new = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *q;

	txt = va_arg(args, char *);

	/*if (txt == NULL)*/
		/*txt = "(AHYY)";*/
	for (p = txt; *p; p++)
	{
		q = old;
		while (*q && *q != *p)
			q++;
		if (*q)
			write(1, &new[q - old], 1);

		else
			write(1, p, 1);

		wc++;
	}
	return (wc);
}
