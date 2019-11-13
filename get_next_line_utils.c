/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:56:28 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 07:21:14 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		str_size;
	int		i;

	str_size = ft_strlen(str);
	if (!(ptr = malloc((str_size + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < str_size)
		ptr[i] = str[i];
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	maxsize;

	i = -1;
	if (s == 0)
		return (NULL);
	maxsize = (start >= ft_strlen(s)) ? 0 : len;
	if (!(substr = malloc((maxsize + 1) * sizeof(char))))
		return (NULL);
	while (++i < maxsize && s[start + i])
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	sizes1;
	size_t	sizes2;
	size_t	i;

	if (s1 == 0 && s2 != 0)
		return (ft_strdup(s2));
	if (s2 == 0 && s1 != 0)
		return (ft_strdup(s1));
	sizes1 = ft_strlen(s1);
	sizes2 = ft_strlen(s2);
	if ((s1 == 0 && s2 == 0) ||
		!(ptr = malloc((sizes1 + sizes2 + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < sizes1)
		ptr[i] = s1[i];
	i = -1;
	while (++i < sizes2)
		ptr[i + sizes1] = s2[i];
	ptr[sizes2 + sizes1] = '\0';
	return (ptr);
}

int	ft_strchr(const char *str, int charset)
{
	int i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == charset)
			return (i + 1);
	}
	return (0);
}