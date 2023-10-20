#include "main.h"

/**
 * print_unsigned - This function prints an unsigned numberber.
 * @list: A list of arguments.
 * @buff: An array used as a buffer for handling the print operation.
 * @flags: A variable that calculates active flags.
 * @width: The specified width for formatting.
 * @precision: The precision specifications for formatting.
 * @size: The size specifier used for formatting.
 * Return: The numberber of characters printed.
 */
int print_unsigned(va_list list, char buff[],
	int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int number = va_arg(list, unsigned long int);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buff[i--] = '0';

	buff[BUFFER_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buff, flags, width, precision, size));
}

/**
 * print_octal - This function prints an unsigned numberber in octal notation.
 * @list: A list of arguments.
 * @buff: An array used as a buffer for handling the print operation.
 * @flags: A variable that calculates active flags.
 * @width: The specified width for formatting.
 * @precision: The precision specification for formatting.
 * @size: The size specifier used for formatting.
 * Return: The numberber of characters printed.
 */
int print_oct(va_list list, char buff[],
	int flags, int width, int precision, int size)
{

	int i = BUFFER_SIZE - 2;
	unsigned long int number = va_arg(list, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buff[i--] = '0';

	buff[BUFFER_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[i--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & HASH && init_number != 0)
		buff[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buff, flags, width, precision, size));
}

/**
 * print_hexadecimal - This function prints an unsigned numberber in hex.
 * @list: A list of arguments.
 * @buff: An array used as a buffer for handling the print operation.
 * @flags: A variable that calculates active flags.
 * @width: The specified width for formatting.
 * @precision: The precision specification for formatting.
 * @size: The size specifier used for formatting.
 * Return: The numberber of characters printed.
 */
int print_hex(va_list list, char buff[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(list, "0123456789abcdef", buff,
		flags, 'x', width, precision, size));
}


int print_hexa_upper(va_list list, char buff[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(list, "0123456789ABCDEF", buff,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal numberber in either lower or upper case.
 * @list: List of arguments.
 * @map_to: Array of values to map the numberber to.
 * @buff: Buffer array for handling print.
 * @flags: Calculates active flags.
 * @flag_ch: Calculates active flags.
 * @width: Specifies the width for formatting.
 * @precision: Precision specification for formatting.
 * @size: Size specifier for formatting.
 * Return: Number of characters printed.
 */
int print_hexa(va_list list, char map_to[], char buff[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int number = va_arg(list, unsigned long int);
	unsigned long int init_number = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buff[i--] = '0';

	buff[BUFFER_SIZE - 1] = '\0';

	while (number > 0)
	{
		buff[i--] = map_to[number % 16];
		number /= 16;
	}

	if (flags & HASH && init_number != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buff, flags, width, precision, size));
}

