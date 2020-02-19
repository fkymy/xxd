#ifndef XXD_H
# define XXD_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>

# define XXD_BUFSIZ 1024

int		lenstr(char *str);
int		cmpstr(char *s, char *t);
int		is_printable(char c);
void	putchar_to_fd(char c, int ofd);
void	putstr_to_fd(char *str, int ofd);
void	putmargin(int option);
char	*memdup(char *buf, int size);
char	*memcat(char *dest, char *buf, size_t size, size_t n);
void	datadump(unsigned char *data, size_t size, int option);
void	put_error(char **argv, int argc, int i, int success);

#endif
