#include "../include/xxd.h"

char	*read_from_fd(int ifd, size_t *size)
{
	int		n;
	char	buf[XXD_BUFSIZ + 1];
	char	*data;
	char	*old;

	data = NULL;
	n = 0;
	*size = 0;
	while ((n = read(ifd, buf, XXD_BUFSIZ)) > 0)
	{
		buf[n] = '\0';
		if (data == NULL)
			data = memdup(buf, n);
		else
		{
			old = data;
			data = memcat(data, buf, *size, n);
			free(old);
		}
		*size += n;
	}
	return (data);
}

void	data_for_stdin(int option)
{
	unsigned char	*data;
	size_t			size;

	data = (unsigned char *)read_from_fd(STDIN_FILENO, &size);
	datadump(data, size, option);
	free(data);
}

void	data_for_files(int argc, char *argv[], int i, int option)
{
	unsigned char	*data;
	int				ifd;
	size_t			size;

	if ((ifd = open(argv[i], O_RDWR, 0)) == -1)
	{
		put_error(argv, argc, i, 0);
		return ;
	}
	data = (unsigned char *)read_from_fd(ifd, &size);
	datadump(data, size, option);
	close(ifd);
	free(data);
}

int		main(int argc, char *argv[])
{
	int i;
	int option;

	option = (argc >= 2 && cmpstr(argv[1], "-C") == 0) ? 1 : 0;
	if (argc == 1)
		data_for_stdin(option);
	else if (argc == 2 && option)
		data_for_stdin(option);
	else
	{
		i = option ? 2: 1;
		while (i < argc)
		{
			data_for_files(argc, argv, i, option);
			i++;
		}
	}
	return (0);
}

