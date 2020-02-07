#include "../include/xxd.h"

char	*memcat(char *dest, char *src, size_t size, size_t n)
{
	char	*res;
	int		i;
	int		k;

	if (size == 0 && n == 0)
	{
		res = (char *)malloc(sizeof(char) * 1);
		res[0] = '\0';
		return (res);
	}
	if (!(res = (char *)malloc(sizeof(char) * (size + n + 1))))
		return (NULL);
	k = 0;
	i = 0;
	while (i < size)
		res[k++] = dest[i++];
	i = 0;
	while (i < n)
		res[k++] = src[i++];
	res[k] = '\0';
	return (res);
}
