#include "../include/xxd.h"

void	puthex(int octet, int digits)
{
	const char *base = "0123456789abcdef";
	if (digits > 1)
		puthex(octet / 16, digits - 1);
	putchar_to_fd(base[octet % 16], 1);
}

void	putascii(char ascii[17], int size)
{
	int i;

	i = 0;
	while (i < size)
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

int		is_dup(unsigned char *data, size_t i, size_t size, int *dup_state)
{
	size_t	j;
	int		count;

	j = 0;
	count = 0;
	while (i + j < size && j < 16)
	{
		if ((int)data[i+j] == (int)data[i+j+1])
			count++;
		j++;
	}
	if (count == 16 && *dup_state)
		return (1);
	else if (count == 16)
		*dup_state = 1;
	else
		*dup_state = 0;
	return (0);
}

void	datadump(unsigned char *data, size_t size, int option)
{
	size_t	i;
	size_t	a;
	char	ascii[17];
	int		dup_state;

	ascii[16] = '\0';
	dup_state = 0;
	i = -1;
	while (++i < size)
	{
		if (i % 16 == 0)
		{
			a = 0;
			if (is_dup(data, i, size, &dup_state))
			{
				putstr_to_fd("*\n", 1);
				i = i + 16 - 1;
				continue ;
			}
			puthex(i, 7 + option);
			putmargin(option);
		}
		ascii[a++] = data[i];
		puthex((int)data[i], 2);

		if ((i + 1) % 8 == 0 || (i + 1) == size)
		{
			putmargin(option);
			if ((i + 1) % 16 == 0)
			{
				if (option)
				{
					putstr_to_fd("|", 1);
					putascii(ascii, a);
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
