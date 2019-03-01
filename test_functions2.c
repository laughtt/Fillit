/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:52:29 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/28 17:49:40 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fillit.h"

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
	{
		(*tet)[*tet_pos].shape = value;
		(*tet)[*tet_pos].id = *tet_pos + 'A';
	}
	else
	{
		(*tet)[*tet_pos].id = *tet_pos + 'A'; 
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

int		ft_get_input(int fd, tet_s  (*tet)[], int *size)
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
	*size = tet_pos + 1;
	if ((*tet)[3].shape == 0)
		return (0);
	return (2);
}
