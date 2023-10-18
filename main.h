#ifndef MAIN_H_
#define MAIN_H_
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>

int _putchar(char c);
int print_char(va_list args, int printed);
int print_string(va_list args, int printed);
int print_integer(va_list args, int printed);
int print_octal(unsigned int num, int printed);
int print_unsigned(unsigned int num, int printed);
int print_reverse(va_list args, int printed);
int print_pointer(va_list args, int printed);
int select(const char *format, va_list args, int printed);
int print_binary(unsigned int num, int printed);
int _printf(const char *format, ...);
int _xhex(unsigned int num, int printed, int uppercase);

#endif
