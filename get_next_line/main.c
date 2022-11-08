#include "get_next_line.h"
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	return (0);
}
