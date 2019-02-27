/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:27:02 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/26 12:32:22 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoinfree(char *s1, const char *s2)
{
	char		*str;

	if ((s1 != NULL && s2 != NULL) && \
			(str = ft_strjoin(s1, s2)))
	{
		free(s1);
		return (str);
	}
	else
		return (NULL);
}

int		ft_store_is_full(char **line, char **store)
{
	char		*p;

	if (*store && (*store)[0] != '\0')
	{
		*line = ft_strjoinfree(*line, *store);
		free(*store);
		if ((p = ft_strchr(*line, '\n')))
		{
			*p = '\0';
			*store = ft_strdup(p + 1);
			return (1);
		}
	}
	return (0);
}

int		ft_check_end_line(char **p, char **line, char *str, char **store)
{
	if ((*p = ft_strchr(str, '\n')))
	{
		**p = '\0';
		*line = ft_strjoinfree(*line, str);
		*store = ft_strdup(*p + 1);
		return (1);
	}
	return (0);
}

void	ft_is_end_of_file(char *p, int bytes, char **store)
{
	if (!(p) && bytes > BUFF_SIZE && *store)
		free(*store);
}

int		get_next_line(const int fd, char **line)
{
	static char		*line_store[FD_MAX] = {NULL};
	char			buf[BUFF_SIZE + 1];
	char			*p;
	int				bytes;

	if (line == NULL || fd < 0 || fd >= FD_MAX || read(fd, buf, 0) < 0 \
			|| BUFF_SIZE <= 0 || !(*line = ft_strnew(1)))
		return (-1);
	if (ft_store_is_full(line, &(line_store[fd])))
		return (1);
	bytes = read(fd, buf, BUFF_SIZE);
	if (bytes == -1)
		return (-1);
	if ((!line_store[fd] || line_store[fd][0] == '\0') && bytes == 0)
		return (0);
	while (bytes > 0)
	{
		buf[bytes] = '\0';
		if (ft_check_end_line(&p, line, buf, &(line_store[fd])))
			return (1);
		*line = ft_strjoinfree(*line, buf);
		ft_is_end_of_file(p, bytes, &(line_store[fd]));
		bytes = read(fd, buf, BUFF_SIZE);
	}
	return (1);
}
