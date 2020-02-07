#include "../include/xxd.h"

char	*memncat(char *dest, char *src, int n)
{
	char	*res;
	int		i;
	int		k;

	if (n == 0)
	{
		res = (char *)malloc(sizeof(char) * 1);
		res[0] = '\0';
		return (res);
	}
	if (!(res = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	k = 0;
	i = 0;
	while (dest[i])
		res[k++] = dest[i++];
	i = 0;
	while (src[i])
		res[k++] = src[i++];
	res[k] = '\0';
	return (res);
}
