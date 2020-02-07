#include "../include/xxd.h"

void	putchar_to_fd(char c, int ofd)
{
	write(ofd, &c, 1);
}

void	putstr_to_fd(char *str, int ofd)
{
	while (*str)
		putchar_to_fd(*str++, ofd);
}
