#ifndef main_h
#define main_h

#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>

typedef struct format_specifiers
{
        char specifier;
        int (*print_f)(va_list list);
} print;

int _printf(const char *format, ...);
int print_char(va_list list);
int print_str(va_list list);
int print_mod(va_list list);

#endif

