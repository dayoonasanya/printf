#include "main.h"
/**
 * printf_char - print character.
 * @args: argument.
 * @p: character.
 *
 * Return: return character.
 */
int printf_char(va_list args, int p)
{
	int c = va_arg(args, int);

	_putchar(c);
	return (p + 1);
}
