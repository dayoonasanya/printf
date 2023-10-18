#include "main.h"
/**
 * print_integer - integer.
 * @args: argument.
 * @p: character.
 *
 *
 * Return: return p.
 */
int print_integer(va_list args, int p)
{
	int n = va_arg(args, int);
	int d = 0;
	int t = n;
	int i;

	if (n < 0)
	{
		p += _putchar('-');
		n = -n;

		t = n;
	}

	do {
		d++;
		t /= 10;
	} while (t != 0);

	while (d > 0)
	{
		int y = 1;
		int x;

		for (x = 1; x < d; x++)
		{
			y *= 10;
		}
		i = n / y;
		p += _putchar(i + '0');
		n -= i * y;
		d--;
	}
	return (p);
}
