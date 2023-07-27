#include "main.h"

/**
 * handle_flag - a function to know which flag exists
 * @string: the string we gonna check
 * Return: flags
 */

int handle_flag(char *string)
{
	int flags = 0;

	switch (*string)
	{
		case '+':
			flags |= flag_P;
			break;
		case '-':
			flags |= flag_M;
			break;
		case '0':
			flags |= flag_Z;
			break;
		case '#':
			flags |= flag_H;
			break;
		case ' ':
			flags |= flag_S;
			break;
	}
	return (flags);
}
