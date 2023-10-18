#include "main.h"

int _printf(const char *format, ...)
{
        va_list list;

        size_t i, j, len = 0;
        size_t array_size;

        print specifier_holder[3] = {
                {'c', print_char},
                {'s', print_str},
                {'%', print_mod},
        };
        array_size = sizeof(specifier_holder) / sizeof(specifier_holder[0]);

        if (format == NULL)
                return (0);

        va_start(list, format);

        for (i = 0; format[i]; i++)
        {
                if (format[i] != '%')
                {
                        write(1, &format[i], 1);
                        len++;
                }
                else
                {
                        i++;
                        for (j = 0; j < array_size; j++)
                        {
                                if (format[i] == specifier_holder[j].specifier)
                                {
                                        len += specifier_holder[j].print_f(list);
                                        break;
                                }
                        }
                        if (j == array_size)
                        {
                                char percent = '%';
                                write(1, &percent, 1);
                                write(1, &format[i], 1);
                                len += 2;
                        }
                }
        }
        return (len);
        va_end(list);
}

