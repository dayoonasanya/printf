#include "format_c.h"
#include <unistd.h>
#include <stdarg.h>

int format_c(va_list args) {
    char c = va_arg(args, int);
    write(1, &c, 1);
    return (1);
}

