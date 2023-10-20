#include "main.h"

/**
 * is_printable - Evaluates printable characters
 * @c: Characters to be evaluated
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hex code to buffer
 * @buffer: Array of characters.
 * @i: Index at which to start appending.
 * @ascii: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii < 0)
		ascii *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii / 16];
	buffer[i] = map_to[ascii % 16];

	return (3);
}

/**
 * is_digit - Verifies if a character is a digit
 * @c: Characters to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a num to the specified size
 * @num: Num to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a num to the specified sizes
 * @num: Num to be casted
 * @size: Num indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

