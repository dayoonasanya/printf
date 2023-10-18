#include "main.h"
/**
 * print_binary - binary number.
 * @n: number.
 * @p: character.
 *
 * Return: return p.
 */
int print_binary(unsigned int n, int p)
{
	int b[32] = {0};
	int j = 0;

	/*Check the number n*/
	if (n == 0)
	{
		_putchar('0');
		p++;
		return (p);
	}

	while (n > 0)
	{
		b[j] = n % 2;
		n /= 2;
		j++;
	}

	while (j > 0)
	{
		j--;
		_putchar('0' + b[j]);
		p++;
	}

	return (p);
}
