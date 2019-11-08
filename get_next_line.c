#include <get_next_line.h>

int get_next_line(int fd, char **line)
{
    static char *buffer = NULL;
    char        *str;
    char        *newBuffer;
    size_t      readSize;
    int         indexCharset;
}