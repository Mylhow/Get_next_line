/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:28:45 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 15:41:49 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

#define ERROR -1
#define SUCCESS 1
#define ENDFILE 0

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

int	ft_free(void *ptr, int code)
{
	free(ptr);
	return (code);
}

int	gnl_check(int fd, char **buffer)
{
	char	*str;
	size_t	read_size;
	int		state;
	char	*buffer_save;

	state = 1;
	if (!(str = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (ERROR);
	if ((read_size = read(fd, str, BUFFER_SIZE)) == -1)
		return (ft_free(str, ERROR));
	str[read_size] = '\0';
	(!ft_strlen(str)) ? state = 0 : 0;
	buffer_save = *buffer;
	if (!(*buffer = ft_strjoin(*buffer, str)))
		return (ft_free(str, ERROR));
	free(buffer_save);
	free(str);
	return (state);
}

int	get_next_line(int fd, char **line)
{
	static char *buffer = NULL;
	char		*new_buffer;
	int			index_charset;
	int			state_gnlcheck;

	(!buffer) ? buffer = ft_strdup("") : 0;
	while (!(index_charset = ft_strchr(buffer, '\n')))
	{
		state_gnlcheck = gnl_check(fd, &buffer);
		if (state_gnlcheck == -1)
			return (-1);
		else if (state_gnlcheck == 0)
			break ;
	}
	new_buffer = NULL;
	if (index_charset != 0)
	{
		*line = ft_substr(buffer, 0, index_charset - 1);
		new_buffer = ft_substr(buffer, index_charset, ft_strlen(buffer));
	}
	else
		*line = ft_strdup(buffer);
	free(buffer);
	buffer = new_buffer;
	return (index_charset == 0) ? ENDFILE : SUCCESS;
}
