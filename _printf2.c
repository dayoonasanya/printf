#include	"main.h"
#include	<stdarg.h>
#include	<unistd.h>
int _printf(const	char *format, ...)
{
va_list args;
int count = 0;
const char *ptr;
va_start(args,	format);
for (ptr = format; *ptr != '\0'; ptr++)
{
if (*ptr != '%')
{
write(1, ptr, 1);
count++;
}
else
{
ptr++;	if (*ptr == 'c')
{
char c = va_arg(args,	int);
write(1, &c, 1);	count++;
}
else if (*ptr == 's')
{
char *str = va_arg(args,	char *);
int i = 0;
while (str[i] != '\0')
{
write(1, &str[i], 1);
count++;
i++;
}
}
else if (*ptr == 'd' || *ptr == 'i')
{​
int num = va_arg(args,	int);
int divisor = 1;
if (num < 0)
{
write(1, "-", 1);
count++;
num *= -1;	}
while (num / divisor > 9)
divisor *= 10;
while (divisor != 0)
{
char digit = '0' + num / divisor;
write(1, &digit, 1);
count++;
num %= divisor;
divisor /= 10;
}
}
else if (*ptr == '%')
{
write(1, "%", 1);	count++;
}
}
}
va_end(args);
return count;
}
