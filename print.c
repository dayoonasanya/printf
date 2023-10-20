#include "main.h"
/**
 * handle_print - Prints an argument based on its type.
 * @fmt: Formatted strings for printing the arguments.
 * @list: List of arguments to be printed.
 * @ind: Ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Get width.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, char_printeds = -1;
	fmt_t fmt_types[] = {
		{'c', print_character}, {'s', print_string}, {'%', print_percent},
		{'i', print_integer}, {'d', print_integer}, {'b', print_bin},
		{'u', print_unsigned}, {'o', print_oct}, {'x', print_hex},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len += write(1, &fmt[*ind], 1);
		return (unknown_len);
	}
	return (char_printeds);
}

