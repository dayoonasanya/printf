#include "main.h"
/**
 * _printf - function implementation
 * @format: specifier.
 *
 * Return: return string.
 */
int _printf(const char *format, ...)
{
	int p = 0;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			p = select(format, args, p);
			format++;
		}
		else
		{
			_putchar(*format);
			p++;
			format++;
		}
	}
	va_end(args);
	return (p);
}
