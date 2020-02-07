#include "../include/xxd.h"

char	*memdup(char *buf, int size)
{
	char	*res;
	int		i;
	/* int		size; */
    /*  */
	/* size = 0; */
	/* while (buf[size] != '\0') */
	/* 	size++; */
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = buf[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
