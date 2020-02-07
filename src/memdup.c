#include "../include/xxd.h"

char	*memdup(char *buf)
{
	char	*res;
	int		i;
	int		size;

	size = 0;
	while (buf[size])
		size++;
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (buf[i])
	{
		res[i] = buf[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

