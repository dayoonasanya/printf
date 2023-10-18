#include "main.h"

int print_char(va_list list)
{
        char i = va_arg(list, int);
        write(1, &i, 1);
        return (1);
}

int print_str(va_list list)
{
        char *str = va_arg(list, char *);
        size_t i = 0;

        if (str == NULL)
                str = "(null)";
        while (str[i])
        {
                write(1, &str[i], 1);
                i++;
        }
        return (1);
}

int print_mod(va_list list)
{
        char j;

        (void)list;
        j = '%';
        write(1, &j, 1);
        return (1);
}

