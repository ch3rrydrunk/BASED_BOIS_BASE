#include <stdlib.h>
#include <stdio.h>

#include "get_next_line.h"

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;

	ret = -100;
	fd = open("get_next_line.h", O_RDONLY);
	while((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
		{
			printf(":(\n");
			exit (-1);
		}
		printf("%s\n", line);
	}
	printf("\n\n\n\n\nThat's it?\n\n\n\n\n");

	fd = open("get_next_line.c", O_RDONLY);
	ret = get_next_line(fd, &line);
	while((ret = get_next_line(fd, &line)))
	{
		if (ret == -1)
		{
			printf(":(\n");
			exit (-1);
		}
		printf("%s\n", line);
	}
	printf("\n\n\n\n\nThat's it?\n\n\n\n\n");

	ret = get_next_line(fd, &line);
	printf("This is bytes read from finished file: %i\n\n", ret);
}