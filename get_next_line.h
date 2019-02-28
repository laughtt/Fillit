/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 15:28:19 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/27 15:56:29 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <libft.h>
# define BUFF_SIZE 1000
# define FD_MAX 4864

int		get_next_line(const int fd, char **line);
char	*ft_strjoinfree(char *s1, const char *s2);
int		ft_store_is_full(char **line, char **store);
int		ft_check_end_line(char **p, char **line, char *str, char **store);
void	ft_is_end_of_file(char *p, int bytes, char **store);

#endif
