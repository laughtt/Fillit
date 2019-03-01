/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:04:45 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/28 17:50:02 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fillit.h"
#include <stdio.h>

void	printmap(tet_s *blocks, int size)
{
	int len;
	int i;
	int k;
	int empty;

	len = size * size;
	while (--len >= 0)
	{
		i = len;
		k = 0;
		empty = 1;
		while (blocks[k].shape)
		{
			if ((blocks[k].shape >> i) & 1)
			{
				empty = 0;
				write(1, &blocks[k].id, 1);
				break ;
			}
			k++;
		}
		if (empty)
			write(1, ".", 1);
		if (len % size == 0)
			write(1, "\n", 1);
	}
}

int		main(int arg, char **argv)
{
	int 		fd;
	tet_s 		tet[MAX_TETROMINOS];
	int 		test;
	int 		i = 0;
	int			size;

	ft_bzero(tet, sizeof(tet));
	if (arg == 2)
	{
		fd = open(argv[1], O_RDONLY);
		test = ft_get_input(fd, &tet, &size);
		if (test)
		{
			while (tet[i++].shape != 0)
				printf("%d \n", size);
			return (1);
		}
		else
			ft_putstr("error\n");
		close(fd);
	}
	else
	{
		display_usage(argv[0]);
		exit(1);
	}
	return (0);
}
