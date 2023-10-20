#include "main.h"

/**
 * handle_write_char - Prints a string.
 * @c: Char types.
 * @buffer: Buffer array for printing.
 * @flags: Calculates active flags.
 * @width: Width specification.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & ZERO)
		pad = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFFER_SIZE - i - 2] = pad;

		if (flags & MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Prints a string.
 * @is_negative: Indicates if the number is negative.
 * @ind: Character types.
 * @buffer: Buffer array for printing.
 * @flags: Calculates active flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size: Size specifier.
 * Return: Number of characters printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFFER_SIZE - ind - 1;
	char pad = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & ZERO) && !(flags & MINUS))
		pad = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & PLUS)
		extra_ch = '+';
	else if (flags & SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		len, pad, extra_ch));
}


int write_num(int ind, char buffer[],
	int flags, int width, int preci,
	int len, char pad, char extra_c)
{
	int i, pad_start = 1;

	if (preci == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (preci == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = pad = ' ';
	if (preci > 0 && preci < len)
		pad = ' ';
	while (preci > len)
		buffer[--ind] = '0', len++;
	if (extra_c != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & MINUS && pad == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & MINUS) && pad == ' ')
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], len));
		}
		else if (!(flags & MINUS) && pad == '0')
		{
			if (extra_c)
				buffer[--pad_start] = extra_c;
			return (write(1, &buffer[pad_start], i - pad_start) +
				write(1, &buffer[ind], len - (1 - pad_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], len));
}

/**
  * write_unsgnd - Writes an unsigned number
  * @is_negative: Indicator for the negativity of the number
  * @ind: Starting index of the number in the buffer
  * @buffer: Array of characters
  * @flags: Flag specifications
  * @width: Width specification
  * @precision: Precision specification
  * @size: Size specification
  *
  * Return: Number of characters written
  */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFFER_SIZE - ind - 1, i = 0;
	char pad = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < len)
		pad = ' ';

	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((flags & ZERO) && !(flags & MINUS))
		pad = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = pad;

		buffer[i] = '\0';

		if (flags & MINUS)
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], len));
		}
	}

	return (write(1, &buffer[ind], len));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Array of characters
 * @ind: Starting index of the number in the buffer
 * @len: Length of the number
 * @width: Width specifier
 * @flags: Flags specifier
 * @pad: Character representing the padding
 * @extra_c: Character representing extra character
 * @pad_start: Index at which padding should start
 *
 * Return: Number of written characters
 */
int write_pointer(char buffer[], int ind, int len,
	int width, int flags, char pad, char extra_c, int pad_start)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & MINUS && pad == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & MINUS) && pad == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], len));
		}
		else if (!(flags & MINUS) && pad == '0')
		{
			if (extra_c)
				buffer[--pad_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_start], i - pad_start) +
				write(1, &buffer[ind], len - (1 - pad_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFFER_SIZE - ind - 1));
}

