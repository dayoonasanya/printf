#include "main.h"
/**
 * _printf - Prints and handle various specifiers
 * @format: Input string with format specifier
 *
 * Return: Len.
 */
int _printf(const char *format, ...)
{
	va_list list;
	size_t len = 0, i = 0, j, array_size;
	print specifier_holder[3] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_mod},
	};
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (0);
	array_size = sizeof(specifier_holder) / sizeof(specifier_holder[0]);
	va_start(list, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			len++;
		}
		else
		{
			i++;
			j = 0;
			for (j = 0; j < array_size; j++)
			{
				if (format[i] == specifier_holder[j].specifier)
				{
					len += specifier_holder[j].print_f(list);
					break;
				}
				if (j == array_size)
				{
					char percent = '%';

					write(1, &percent, 1);
					write(1, &format[i], 1);
					len += 2;
				}
			}
		}
	}
	if (format[i] == '\n')
		write(1, &newline, 1);
	return (len);
	va_end(list);
}

