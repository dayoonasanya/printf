#include "main.h"
/**
 * print_octal - prints.
 * @n: number.
 * @p: printed.
 *
 * Return: return p.
 */
int print_octal(unsigned int n, int p)
{
	int a[100], i = 0, j;

	while (n != 0)
	{
		int rem = n % 8;

		a[i] = 48 + rem;
		i++;
		n /= 8;
	}

	if (i == 0)
	{
		_putchar('0');
		p++;
	}
	else
	{
		for (j = i - 1; j >= 0; j--)
		{
			_putchar(a[j]);
			p++;
		}
	}
	return (p);
}
