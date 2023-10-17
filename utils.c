#include "utils.h"


void custom_puts(const char *str) 
{
	while (*str) 
	{
		putchar(*str);
		str++;
	}
}


int custom_strlen(const char *str) 
{
	int len = 0;
	while (*str) 
	{
		len++;
		str++;
	}
	return len;
}

