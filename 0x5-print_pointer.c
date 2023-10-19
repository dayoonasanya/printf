#include "main.h"

#define MAX_HEX_DIGITS 16
/**
 * print_pointer - pointer.
 * @args: arguments.
 * @p: printed.
 *
 * Return: return p
 */

int print_pointer(va_list args, int p)
{
	void *ptr = va_arg(args, void*);
	unsigned long n = (unsigned long) ptr;
	int d = 0;
	int i;
	unsigned long tmp = n;
	char h_d[MAX_HEX_DIGITS] = "0123456789abcdef";
	char ex[MAX_HEX_DIGITS];

	while (tmp != 0)
	{
		d++;
		tmp /= 16;
	}

	p += _putchar('0');
	p += _putchar('x');

	if (n == 0)
	{
		p += _putchar('0');
	}
	else
	{
		for (i = d - 1; i >= 0; i--)
		{
			int dgt = n % 16;

			ex[i] = h_d[dgt];
			n /= 16;
		}
		for (i = 0; i < d; i++)
		{
			p += _putchar(ex[i]);
		}
	}
	return (p);
}
