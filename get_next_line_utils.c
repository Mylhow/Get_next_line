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