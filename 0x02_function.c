#include "main.h"

/**
 * print_pointer - Prints the value of a pointer variable.
 * @types: List of arguments.
 * @buffer: Buffer array for handling print.
 * @flags: Calculates active flags.
 * @width: Specifies the width for formatting.
 * @precision: Precision specifications for formatting.
 * @size: Size specifier for formatting.
 * Return: Number of characters printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c_ext = 0, pad = ' ';
	int i = BUFFER_SIZE - 2, length = 2, pad_begin = 1;
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[i--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}

	if ((flags & ZERO) && !(flags & MINUS))
		pad = '0';
	if (flags & PLUS)
		c_ext = '+', length++;
	else if (flags & SPACE)
		c_ext = ' ', length++;

	i++;

	return (write_pointer(buffer, i, length,
		width, flags, pad, c_ext, pad_begin));
}

