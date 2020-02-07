#include "../include/xxd.h"

void	puthex(int octet, int digits)
{
	const char *base = "0123456789abcdef";
	if (digits > 1)
		puthex(octet / 16, digits - 1);
	putchar_to_fd(base[octet % 16], 1);
}

void	datadump(unsigned char *data, size_t size, int option)
{
	size_t	i;
	int				dupcount = 0;
	int				is_duprow = 0;

	if (option)
		putstr_to_fd("option!", 1);

	i = -1;
	while (++i < size)
	{
		if (i % 16 == 0)
		{
			if (dupcount == 16 && is_duprow)
			{
				putstr_to_fd("*\n", 1);
				continue ;
			}
			else if (dupcount == 16)
				is_duprow = 1;
			else
				is_duprow = 0;
			dupcount = 0;
			puthex(i, 7 + option);
			putstr_to_fd(" ", 1);
		}
		if (i > 0 && (int)data[i] == (int)data[i - 1])
			dupcount++;
		puthex((int)data[i], 2);
		if ((i + 1) % 16 == 0)
			putstr_to_fd("\n", 1);
		else if ((i + 1) == size)
		{
			putstr_to_fd("\n", 1);
			puthex(i + 1, 7 + option);
			putstr_to_fd("\n", 1);
		}
		else
			putstr_to_fd(" ", 1);
	}
	return ;
	/* while (data[i]) */
	/* { */
	/* 	printf("%02X ", data[i]); */
	/* 	if (is_printable(data[i])) */
	/* 		ascii[i % 16] = data[i]; */
	/* 	else */
	/* 		ascii[i % 16] = '.'; */
    /*  */
	/* 	i++; */
	/* 	count++; */
	/* 	if (count % 16 == 0) */
	/* 		printf("\n"); */
	/* } */
}
