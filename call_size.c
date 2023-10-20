#include "main.h"

/**
 * get_size - Calculates the size to cast the argument.
 * @format: Formatted strings for printing the arguments.
 * @i: List of arguments to be printed.
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int current_i = *i + 1;
	int size = 0;

	if (format[current_i] == 'l')
		size = LONG;
	else if (format[current_i] == 'h')
		size = SHORT;

	if (size == 0)
		*i = current_i - 1;
	else
		*i = current_i;

	return (size);
}

