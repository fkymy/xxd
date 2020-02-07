#include "../include/xxd.h"

int		lenstr(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		cmpstr(char *s, char *t)
{
	while (*s == *t)
	{
		if (*s == '\0')
			return (0);
		s++;
		t++;
	}
	return (*s - *t);
}

int		is_printable(char c)
{
	if (c >= 32 && c != 127)
		return (1);
	else
		return (0);
}
