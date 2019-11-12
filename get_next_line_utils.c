#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i])
        i++;
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

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *substr;
        size_t  i;
        size_t  maxsize;

        i = -1;
        if (s == 0)
            return (NULL);
        maxsize = (start >= ft_strlen(s)) ? 0 : len;
        if (!(substr = malloc((maxsize + 1) * sizeof(char))))
            return (NULL);
        while (++i < maxsize)
            substr[i] = s[start + i];
        substr[i] = '\0';
        return (substr);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *ptr;
        size_t  maxsize;
        size_t  sizes1;

        if (s1 == 0 && s2 != 0)
                return ((char *)s2);
        if (s2 == 0 && s1 != 0)
                return ((char *)s1);
        sizes1 = ft_strlen(s1);
        maxsize = sizes1 + ft_strlen(s2) + 1;
        if ((s1 == 0 && s2 == 0) || !(ptr = malloc(maxsize * sizeof(char))))
                return (NULL);
        ft_memcpy(ptr, s1, sizes1 + 1);
        ft_strlcat(ptr, s2, maxsize);
        return (ptr);
}