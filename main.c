/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:07:15 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/26 16:49:13 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_check_parallels(unsigned int num)
{
	unsigned int   first_8bits;
	unsigned char first_4bits;

	if (num < 15)
		return (1);
	first_8bits = (num & 0xff);
	first_4bits = (first_8bits << 4) >> 4;
	first_8bits = first_8bits >> 4;
	if ((int)(first_8bits & first_4bits) > 0)
		return (1);
	return (0);
}

int		ft_check_adjacents(int adjacents, int count)
{
	int		i;

	i = 1;
	while (i < count)
	{
		adjacents = (adjacents & (adjacents << 1));
		if (adjacents)
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_check_bits(int num, int *bites, int size)
{
	int			adjacents;
	unsigned int count;
	int 		i;
	unsigned int		paralle;

	i = 0;
	count = 0;
	paralle = num;
	adjacents = num - ((num >> 4) << 4);
	while(i++ < 4)
	{
		count += num & 1;
		num >>= 1;
	}
	*bites = *bites + count;
	if (count > 1)
		if (!ft_check_adjacents(adjacents, count))
			return (0);
	if (*bites > 1 && *bites < 4)
		if (!ft_check_parallels(paralle))
			return (0);
	return (1);
}

unsigned	int		ft_line_to_int(char *line)
{
	int		i;
	unsigned int 	num;
	unsigned int	array[4] = {8,4,2,1};

	num = 0;
	i = -1;
	while (*(line + ++i))
		if (*(line + i) == '#')
			num = array[i] + num;
	return (num);
}

int 	ft_check_box(int num, int line_box_pos)
{
	static int		bites = 0;
	int				size;

	size = 4;
	if ((line_box_pos + 1) % 5 == 0)
	{
		if (bites != 4)
			return (0);
		bites = 0;
		return (1);
	}
	if (!ft_check_bits(num, &bites,size))
		return (0);
	if (bites > 4)
		return (0);
	return (1);
}

int			ft_add_to_struct(char *line, tet_s (*tet)[], int line_box_pos, int *tet_pos)
{
	unsigned int	value;
	
	value = 0;
	if ((line_box_pos + 1) % 5 == 0)
		return (++(*tet_pos));
	value = ft_line_to_int(line);
	if ((*tet)[*tet_pos].shape == 0)
		(*tet)[*tet_pos].shape = value;
	else
	{
		(*tet)[*tet_pos].shape = ((*tet)[*tet_pos].shape << 4u) + value;
	}
	return (1);
}

int			ft_check_line(char *line, int line_box_pos)
{
	int		i;

	i = 0;
	if ((line_box_pos + 1) % 5 == 0 && *(line) == '\0')
		return (4);
	while(*(line + i) == '.' || *(line + i) == '#')
		i++;
	if (i == 4 && *(line + i) == '\0')
		return (10);
	return (0);
}

int		ft_get_input(int fd, tet_s  (*tet)[])
{
	char	*line;
	int 	line_box_pos;
	int		tet_pos;

	tet_pos = 0;
	line_box_pos = 0;
	while (get_next_line(fd, &line))
	{
		if (!ft_check_line(line, line_box_pos))
			return (0);
		if (!ft_add_to_struct(line, tet, line_box_pos,&tet_pos))
			return (0);
		if (!ft_check_box(((*tet)[tet_pos]).shape, line_box_pos))
			return (0);
		line_box_pos++;
	}
	if ((*tet)[3].shape == 0)
		return (0);
	return (2);
}

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
		printf("%d", test);
		if (test)
				return (1);
		else
			printf("error");
	}
	return (0);
}
