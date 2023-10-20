#include "main.h"

/**
 * print_non_printable - Prints ASCII codes in hexx of non-printable.
 * @types: List of arguments.
 * @buffer: Buffer array for handling print.
 * @flags: Calculates active flags.
 * @width: Specifies the width for formatting.
 * @precision: Precision specification for formatting.
 * @size: Size specifier for formatting.
 * Return: Number of characters printed.
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, off = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + off] = str[i];
		else
			off += append_hexa_code(str[i], buffer, i + off);

		i++;
	}

	buffer[i + off] = '\0';

	return (write(1, buffer, i + off));
}

/**
 * print_reverse - Prints a reversed string.
 * @types: List of arguments.
 * @buffer: Buffer array for handling print.
 * @flags: Calculates active flags.
 * @width: Specifies the width for formatting.
 * @precision: Precision specification for formatting.
 * @size: Size specifier for formatting.
 * Return: Number of characters printed.
 */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

