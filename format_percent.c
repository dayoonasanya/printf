#include "format_percent.h"
#include <unistd.h>
#include <stdarg.h>

int format_percent(va_list args)
{
	(void)args; 
	write(1, "%", 1);
	return 1; 
}

