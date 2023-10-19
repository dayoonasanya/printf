#include "main.h"
/**
 * print_unsigned - unsigned.
 * @n: numbers.
 * @p: printed.
 *
 * Return: return p
 */
int print_unsigned(unsigned int n, int p)
{
	int d = 0;
	unsigned int tmp = n;

	do {
		d++;
		tmp /= 10;
	} while (tmp != 0);

	if (n == 0)
	{
		_putchar('0');
		p++;
	}
	else
	{
		char unsigned_s[11];
		int i = 0;

		while (n != 0)
		{
			unsigned_s[i] = (n % 10) + '0';
			n /= 10;
			i++;
		}
		for (i = d - 1; i >= 0; i--)
		{
			_putchar(unsigned_s[i]);
			p++;
		}
	}
	return (p);
}
