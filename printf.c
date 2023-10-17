#include "printf.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Custom implementation of the printf function.
 * @format: A format string specifying the format of the output.
 *
 * Return: The number of characters printed (excluding the null byte).
 */

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;

	va_start(args, format);


	va_end(args);
	return (printed_chars);
}
