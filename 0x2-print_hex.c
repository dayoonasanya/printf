#include "main.h"
/**
 * _xhex - hex number.
 * @n: arguements
 * @p: character.
 * @up: uppercase.
 *
 *
 * Return: return hex.
 */
int _xhex(unsigned int n, int p, int up)
{
	int a[100], x = 0, y;

	while (n != 0)
	{
		int rem = n % 16;

		if (rem < 10)
		{
			a[x] = 48 + rem;
		}
		else
		{
			if (up)
			{
				a[x] = 65 + (rem - 10);
			}
			else
			{
				a[x] = 97 + (rem - 10);
			}
		}
		x++;
		n /= 16;
	}
	if (x == 0)
	{
		_putchar('0');
		p++;
	}
	else
	{
		for (y = x - 1; y >= 0; y--)
		{
			_putchar(a[y]);
			p++;
		}
	}
	return (p);
}
