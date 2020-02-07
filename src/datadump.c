#include "../include/xxd.h"

void	puthex(int octet, int digits)
{
	const char *base = "0123456789abcdef";
	if (digits > 1)
		puthex(octet / 16, digits - 1);
	putchar_to_fd(base[octet % 16], 1);
}

void	putascii(char ascii[17], int k)
{
	int i;

	i = 0;
	while (i < k)
	{
		if (is_printable(ascii[i]))
			putchar_to_fd(ascii[i], 1);
		else
			putstr_to_fd(".", 1);
		i++;
	}
}

void	putlastoffset(int offset, int option)
{
	putstr_to_fd("\n", 1);
	puthex(offset + 1, 7 + option);
	putstr_to_fd("\n", 1);
}

void	datadump(unsigned char *data, size_t size, int option)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		dupcount;
	int		is_duprow;
	char	ascii[17];

	dupcount = 0;
	is_duprow = 0;
	ascii[16] = '\0';
	i = -1;
	while (++i < size)
	{
		if (i % 16 == 0)
		{
			j = 0;
			k = 0;
			while (i + j < size && j < 16)
			{
				if ((int)data[i + j] == (int)data[i + j + 1])
					dupcount++;
				j++;
			}
			if (dupcount == 16 && is_duprow)
			{
				putstr_to_fd("*\n", 1);
				i = i + 15;
				continue ;
			}
			else if (dupcount == 16)
				is_duprow = 1;
			else
				is_duprow = 0;
			dupcount = 0;
			puthex(i, 7 + option);
			putmargin(option);
		}

		ascii[k++] = data[i];
		puthex((int)data[i], 2);

		if ((i + 1) % 8 == 0 || (i + 1) == size)
		{
			putmargin(option);
			if ((i + 1) % 16 == 0)
			{
				if (option)
				{
					putstr_to_fd("|", 1);
					putascii(ascii, k);
					putstr_to_fd("|", 1);
				}
				if ((i + 1) == size)
					putlastoffset(i, option);
				putstr_to_fd("\n", 1);
			}
			else if ((i + 1) == size)
				putlastoffset(i, option);
		}
		else
			putstr_to_fd(" ", 1);
	}
}
