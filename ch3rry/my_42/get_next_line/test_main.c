#include <stdlib.h>
#include <stdio.h>

#include "get_next_line.h"

# include <string.h>
# include <strings.h>
# include <ctype.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <regex.h>
# include <assert.h>

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;

	ret = -100;
	fd = open("/Users/caellis/BASE/ch3rry/my_42/get_next_line/sandbox/large_file.txt", O_RDONLY);
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
	sleep(30);
}