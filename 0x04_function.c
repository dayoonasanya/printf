#include "main.h"

/**
 * print_int - This function prints an integer.
 * @list: A list of arguments.
 * @buff: An array used as a buffer for handling the print operation.
 * @flag: A variable that calculates active flags.
 * @width: The specified width for formatting.
 * @precision: The precision specification for formatting.
 * @size: The size specifier used for formatting.
 * Return: The number of characters printed.
 */
int print_integer(va_list list, char buff[],
	int flag, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(list, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buff[i--] = '0';

	buff[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buff, flag, width, precision, size));
}

/**
 * print_binary - This function prints an unsigned number in bin format.
 * @list: A list of arguments.
 * @buff: An array used as a buffer for handling the print operation.
 * @flag: A variable that calculates active flags.
 * @width: The specified width for formatting.
 * @precision: The precision specification for formatting.
 * @size: The size specifier used for formatting.
 * Return: The number of characters printed.
 */
int print_bin(va_list list, char buff[],
	int flag, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(list, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

