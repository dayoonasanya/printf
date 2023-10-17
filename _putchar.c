#include "main.h"
#include <unistd.h>
/**
 * _putchar - prints a character to stdout.
 * @c: character.
 * Return: 0 or 1.
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}

