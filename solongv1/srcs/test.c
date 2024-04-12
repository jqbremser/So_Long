#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char *file = "so_long.c";
	int fd = open(file, O_RDONLY);
	char *line;

	line = get_next_line(fd);
	while(line)
	{
		printf("%s\n", line);
		line = get_next_line(fd);
	}
	return (0);
}