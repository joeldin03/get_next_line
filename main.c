#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        printf("Line read: %s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}
