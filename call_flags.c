#include "main.h"

/**
 * get_flags - Calculates active flags.
 * @format: Formatted strings for printing the arguments.
 * @i: Parameter to take.
 * Return: Flags.
 */
int get_flags(const char *format, int *i)
{
	int j, current_i;
	int flags = 0;
	const char CH_FLAG[] = {'-', '+', '0', '#', ' ', '\0'};
	const int ARR_FLAGS[] = {MINUS, PLUS, ZERO, HASH, SPACE, 0};

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		for (j = 0; CH_FLAG[j] != '\0'; j++)
			if (format[current_i] == CH_FLAG[j])
			{
				flags |= ARR_FLAGS[j];
				break;
			}

		if (CH_FLAG[j] == 0)
			break;
	}

	*i = current_i - 1;

	return (flags);
}

