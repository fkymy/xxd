#include "../include/xxd.h"

int		compare_str(char *s, char *t)
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

char	*read_from_stdin(void)
{
	int n;
	char buf[1024];
	char *content;
	char *old;
	int size;

	content = NULL;
	size = 0;
	while ((n = read(0, buf, 1024)) > 0)
	{
		printf("n: %d\n", n);
		printf("buf: %s\n", buf);
		if (content == NULL)
			content = memdup(buf);
		else
		{
			old = content;
			content = memncat(content, buf, size + n);
			free(old);
		}
		size += n;
	}
	return (content);
}

int	main_for_stdin(int argc, char *argv[], int option)
{
	char *content;

	if (option)
		printf("option");
	content = read_from_stdin();
	printf("%s\n", content);
	return (0);
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		return (main_for_stdin(argc, argv, 0));
	if (argc == 2 && compare_str(argv[1], "-C"))
		return (main_for_stdin(argc, argv, 1));
	else
	{
		printf("read from file");
	}
	return (0);
}
