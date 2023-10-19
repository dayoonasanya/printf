#include "main.h"
/**
 * print_reverse - reverse.
 * @args: arguments.
 * @p: printed.
 *
 * Return: return p.
 */
int print_reverse(va_list args, int p)
{
	char *str = va_arg(args, char *);
	int len = 0, i;

	while (str[len])
	{
		len++;
	}

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(str[i]);
		p++;
	}

	return (p);
}
