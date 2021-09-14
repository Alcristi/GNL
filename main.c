#include "get_next_line.h"
#include "get_next_line.c"
#include "get_next_line_utils.c"

#include <fcntl.h>
int main()
{
	int fd;
	int i;
	char *test;

	i = 0;
	fd = open("./gnlTester/files/alternate_line_nl_with_nl",O_RDONLY);
	while (test = get_next_line(fd))
	{
		printf("%s",test);
	}
	close(fd);
}
