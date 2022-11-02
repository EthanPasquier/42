#include "get_next_line.h"
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

	// t_s	test;
	fd = open("test.dict", O_RDONLY);
	// printf("%d\n", test.comptbuf);
	printf("premier = \'%s\'", get_next_line(fd));
	printf("\ndeuxieme = \'%s\'\n", get_next_line(fd));
	// get_next_line(fd);
	// printf("\n%d", test.comptbuf);
	return (0);
}
