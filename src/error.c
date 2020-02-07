#include "../include/xxd.h"

void	put_error(char **argv, int argc, int i, int success)
{
	putstr_to_fd(basename(argv[0]), STDERR_FILENO);
	putstr_to_fd(": ", STDERR_FILENO);
	putstr_to_fd(argv[i], STDERR_FILENO);
	if (errno == EACCES)
		putstr_to_fd(": Permission Denied\n", STDERR_FILENO);
	else if (errno == EISDIR)
		putstr_to_fd(": Is a directory\n", STDERR_FILENO);
	else
	{
		putstr_to_fd(": No such file or directory\n", STDERR_FILENO);
		if (i == argc - 1 && success == 0)
		{
			putstr_to_fd(basename(argv[0]), STDERR_FILENO);
			putstr_to_fd(": ", STDERR_FILENO);
			putstr_to_fd(argv[i], STDERR_FILENO);
			putstr_to_fd(": Bad file descriptor\n", STDERR_FILENO);
		}
	}
}
