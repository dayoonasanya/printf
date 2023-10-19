#include "main.h"
/**
 * print_string - string.
 * @args: arguments.
 * @p: printed.
 *
 * Return: return p.
 */
int print_string(va_list args, int p)
{
	char *s = va_arg(args, char *);

	while (*s != '\0')
	{
		_putchar(*s);
		p++;
		s++;
	}
	return (p);
}
