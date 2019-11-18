/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dgascon <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/12 15:56:17 by dgascon      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 12:03:02 by dgascon     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR -1
# define SUCCESS 1
# define ENDFILE 0

typedef struct	s_list
{
	int				fd;
	char			*buffer;
	struct s_list	*next;
}				t_lst;

size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strchr(const char *str, int charset);
int				gnl_line(char *buffer, char **line, int index);
int				get_next_line(int fd, char **line);
#endif
