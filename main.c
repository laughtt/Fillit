/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 16:04:45 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/27 16:24:51 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fillit.h"

int		main(int arg, char **argv)
{
	int 		fd;
	tet_s 		tet[MAX_TETROMINOS];
	int 		test;

	ft_bzero(tet, sizeof(tet));
	if (arg == 2)
	{
		fd = open(argv[1], O_RDONLY);
		test = ft_get_input(fd, &tet);
		if (test)
				return (1);
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
