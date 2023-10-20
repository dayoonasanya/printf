#include "main.h"

/**
 * print_char - This function prints a single character.
 * @list: A list of arguments.
 * @buff: An array used as a buffer for handling the print operation.
 * @flag: A variable that calculates active flags.
 * @width: The specified width for formatting.
 * @precision: The precision specification for formatting.
 * @size: The size specifier used for formatting.
 * Return: The number of characters printed.
 */
int print_character(va_list list, char buff[],
	int flag, int width, int precision, int size)
{
	char c = va_arg(list, int);

	return (handle_write_char(c, buff, flag, width, precision, size));
}

/**
 * print_string - This function prints a string.
 * @list: A list of arguments.
 * @buff: An array used as a buffer for handling the print operation.
 * @flag: A variable that calculates active flags.
 * @width: The specified width for formatting.
 * @precision: The precision specification for formatting.
 * @size: The size specifier used for formatting.
 * Return: The number of characters printed.
 */
int print_string(va_list list, char buff[],
	int flag, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(list, char *);

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flag & MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**
 * print_percent - This function prints a percent sign.
 * @list: A list of arguments.
 * @buff: An array used as a buffer for handling the print operation.
 * @flag: A variable that calculates active flags.
 * @width: The specified width for formatting.
 * @precision: The precision specification for formatting.
 * @size: The size specifier used for formatting.
 * Return: The number of characters printed.
 */
int print_percent(va_list list, char buff[],
	int flag, int width, int precision, int size)
{
	UNUSED(list);
	UNUSED(buff);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

