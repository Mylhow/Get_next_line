#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    if (s)
    {
        while (s[i])
            i++;
    }
    return (i);
}

char    *ft_strdup(const char *str)
{
    char    *ptr;
    int     strSize;
    int     i;

    strSize = ft_strlen(str);
    if (!(ptr = malloc((strSize + 1) * sizeof(char))))
        return (NULL);
    i = -1;
    while (++i < strSize)
        ptr[i] = str[i];
    ptr[i] = '\0';
    return (ptr);
}

void    *ft_calloc(size_t count, size_t size)
{
    char    *m;
    int     i;
    int     totalSize;

    totalSize = count * size;
    if (!(m = malloc(totalSize)))
        return (NULL);
    i = -1;
    while (++i < totalSize)
        m[i] = '\0';
    return (m);    
}