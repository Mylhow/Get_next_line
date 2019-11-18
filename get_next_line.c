/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:28:45 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 15:49:43 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE_H
# define BUFFER_SIZE 1
#endif

t_lst	*gnl_new(int fd, char *buffer)
{
	t_lst *current;

	if (!(current = malloc(sizeof(t_lst))))
		return (NULL);
	if (!buffer)
	{
		if (!(current->buffer = ft_substr("", 0, 1)))
			return (NULL);
	}
	else
		current->buffer = buffer;
	current->fd = fd;
	current->next = NULL;
	return (current);
}

t_lst	*gnl_fct(t_lst **lsts, int fd, char *buffer)
{
	t_lst *current;

	if (!(current = (*lsts)))
		return (((*lsts) = gnl_new(fd, buffer)));
	while (current)
	{
		if (current->fd == fd)
			break ;
		else if (!(current->next))
			return ((current->next = gnl_new(fd, buffer)));
		(current) = (current)->next;
	}
	return (current);
}

int		gnl_check(int fd, char **buffer)
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

int		get_next_line(int fd, char **line)
{
	static t_lst	*buffer;
	t_lst			*current;
	char			*new_buffer;
	int				i;
	int				state_gnlcheck;

	new_buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || !(current = gnl_fct(&buffer, fd, NULL)))
		return (ERROR);
	while (!(i = ft_strchr(current->buffer, '\n')))
		if ((state_gnlcheck = gnl_check(fd, &current->buffer)) == -1)
			return (ERROR);
		else if (state_gnlcheck == 0)
			break ;
	if ((i > 0) &&
		!(new_buffer =
			ft_substr(current->buffer, i, ft_strlen(current->buffer))))
		return (ERROR);
	if (gnl_line(current->buffer, line, i) == -1)
		return (ERROR);
	free(current->buffer);
	current->buffer = (!new_buffer) ? NULL : new_buffer;
	return (i == 0) ? ENDFILE : SUCCESS;
}
