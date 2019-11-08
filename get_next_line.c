#include <get_next_line.h>

#define Error -1
#define Success 1
#define EndOfFile 0

int ft_free(void *ptr, int code)
{
    free(ptr);
    return (code);
}

int get_next_line(int fd, char **line)
{
    static char *buffer = NULL;
    char        *str;
    char        *newBuffer;
    size_t      readSize;
    int         indexCharset;

    readSize = 1;
    while (readSize)
    {
        if (!(str = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
            return (Error);
        if ((readSize = read(fd, str, BUFFER_SIZE)) == -1)
            return(ft_free(str, Error));
        if (!(buffer = ft_strjoin(buffer, str)))
            return (ft_free(str, Error));
        free(str);
    }
}