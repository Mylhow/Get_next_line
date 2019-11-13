/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:28:45 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 11:23:33 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

#define ERROR -1
#define SUCCESS 1
#define ENDFILE 0

int	gnl_check(int fd, char **buffer)
{
	char	*str;
	int		read_size;
	int		state;
	char	*buffer_save;

	state = 1;
	if (!(str = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (ERROR);
	if ((read_size = read(fd, str, BUFFER_SIZE)) == -1)
	{
		free(str);
		return (ERROR);
	}
	str[read_size] = '\0';
	(!ft_strlen(str)) ? state = 0 : 0;
	buffer_save = *buffer;
	if (!(*buffer = ft_strjoin(*buffer, str)))
	{
		free(str);
		return (ERROR);
	}
	free(buffer_save);
	free(str);
	return (state);
}

int	get_next_line(int fd, char **line)
{
	static char *buffer[255];
	char		*new_buffer;
	int			i_charset;
	int			state_gnlcheck;

	if (fd < 0)
		return (-1);
	(!buffer[fd]) ? buffer[fd] = ft_strdup("") : 0;
	while (!(i_charset = ft_strchr(buffer[fd], '\n')))
	{
		if ((state_gnlcheck = gnl_check(fd, &buffer[fd])) == -1)
			return (-1);
		else if (state_gnlcheck == 0)
			break ;
	}
	new_buffer = NULL;
	(i_charset != 0) ? *line = ft_substr(buffer[fd], 0, i_charset - 1) : 0;
	if (i_charset)
		new_buffer = ft_substr(buffer[fd], i_charset, ft_strlen(buffer[fd]));
	else
		*line = ft_strdup(buffer[fd]);
	free(buffer[fd]);
	buffer[fd] = (!new_buffer) ? NULL : new_buffer;
	return (i_charset == 0) ? ENDFILE : SUCCESS;
}
