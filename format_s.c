#include "format_s.h"
#include <unistd.h>
#include <stdarg.h>

int format_s(va_list args) {
    char *str = va_arg(args, char *);
    int len = 0;
    while (str && *str) {
        write(1, str, 1);
        str++;
        len++;
    }
    return len; 
}

