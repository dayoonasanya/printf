#include "main.h"
/**
 * select - select.
 * @args: argument.
 * @p: printed.
 * @format: format.
 *
 * Return: return p.
 */
int select(const char *format, va_list args, int p)
{
	switch (*format)
	{
		case 'd':
		case 'i':
			p = print_integer(args, p);
			break;
		case 'c':
			_putchar(va_arg(args, int));
			p++;
			break;
		case 's':
			p = print_string(args, p);
			break;
		case '%':
			_putchar('%');
			p++;
			break;
		case 'b':
			p = print_binary(va_arg(args, unsigned int), p);
			break;
		case 'x':
		case 'X':
			p = _xhex(va_arg(args, unsigned int), p, (*format == 'X') ? 1 : 0);
			break;
		case 'o':
			p = print_octal(va_arg(args, unsigned int), p);
			break;
		case 'u':
			p = print_unsigned(va_arg(args, unsigned int), p);
			break;
		case 'r':
			p = print_reverse(args, p);
			break;
		case 'p':
			p = print_pointer(args, p);
			break;
		default:
			break;
	}
	return (p);
}
