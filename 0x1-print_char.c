#include "main.h"
/**
 * print_char - print character.
 * @args: argument.
 * @p: character.
 *
 * Return: return character.
 */
int print_char(va_list args, int p)
{
	int c = va_arg(args, int);

	_putchar(c);
	return (p + 1);
}
