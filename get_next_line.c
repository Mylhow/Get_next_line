/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:28:45 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 15:33:27 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

#define Error -1
#define Success 1
#define EndOfFile 0

int ft_strchr(const char *str, int charset)
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

int ft_free(void *ptr, int code)
{
	free(ptr);
	return (code);
}

int	gnl_check(int fd, char **buffer)
{
	char        *str;
	size_t      readSize;
	int			state;	
	char		*buffer_save;

	state = 1;
	if (!(str = malloc((BUFFER_SIZE + 1) *sizeof(char))))
		return (Error);
	if ((readSize = read(fd, str, BUFFER_SIZE)) == -1)
		return(ft_free(str, Error));
	str[readSize] = '\0';
	(!ft_strlen(str)) ? state = 0 : 0;
	buffer_save = *buffer;		
	if (!(*buffer = ft_strjoin(*buffer, str)))
		return (ft_free(str, Error));
	free(buffer_save);
	free(str);
	return (state);
}

int get_next_line(int fd, char **line)
{
	static char *buffer = NULL;
	char        *newBuffer;
	int         indexCharset;
	int			stateGNLCheck;

	(!buffer) ? buffer = ft_strdup("") : 0;
	while (!(indexCharset = ft_strchr(buffer, '\n')))
	{
		stateGNLCheck = gnl_check(fd, &buffer);
		if (stateGNLCheck == -1)
			return (-1);
		else if (stateGNLCheck == 0)
			break ;
	}
	if (indexCharset != 0)
	{
		*line = ft_substr(buffer, 0, indexCharset - 1);
		newBuffer = ft_substr(buffer, indexCharset, ft_strlen(buffer));
	}
	else
	{
		newBuffer = NULL;
		*line = ft_strdup(buffer);
	}
	free(buffer);
	buffer = newBuffer;
	return (indexCharset == 0) ? 0 : 1;
}
