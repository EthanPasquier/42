#include "get_next_line.h"
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// get_next_line(fd);
	// printf("\n\n");
	// get_next_line(fd);
	return (0);
}
