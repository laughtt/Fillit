/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 09:30:05 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/28 16:00:47 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long long	increase_map(unsigned long long map, int size)
{
	unsigned long long	new;
	unsigned long long	temp;
	int		i;
	int		pos;

	new = 0;
	i = 1;
	pos = size;
	while (pos > 0)
	{
		temp = map;
		if (pos != size)
			temp = remove_above(temp, pos, size);
		temp = temp >> ((size * size) - (size * i));
		temp = temp << ((((size + 1) * (size + 1)) - ((size + 1) * i)) + 1);
		new = new & temp;
		pos--;
		i++;
	}
	return (new);
}

tet_s				*increase_blocks(tet_s (blocks)[], int size)
{
	int i;

	i = 0;
	while ((blocks)[i])
	{
		blocks[i].shape = reset_block(blocks[i], size);
		blocks[i].shape = increase_map(blocks[i].shape, size);
		i++;
	}
	return (blocks);
}

tet_s				*duplicate(tet_s (blocks))
{
	tet_s	new_blocks[MAX_TETROMINOS];
	int 	i;

	i = 0;
	while (blocks[i])
	{
		new_blocks[i].shape = blocks[i].shape;
		new_blocks[i].id = blocks[i].id;
		i++;
	}
	return (new_blocks);
}

tet_s				*solvehelper(tet_s (blocks)[], unsigned long long map, int size, int idx)
{
	tet_s *temp;

	if (!(*blocks))
		return (0);
	if (!(*blocks)[idx])
		return (blocks);
	if (!(check_fit(map, (blocks)[idx].shape) && shift((blocks)[idx].shape, size)))
	{
		blocks[idx].shape = shift(blocks[idx].shape, size);
        return (solvehelper(blocks, map, size, idx));
	}
	if (!(check_fit(map, blocks[idx].shape)))
    {
		map = increase_map(map, size);

		blocks = increase_blocks(blocks, size);
        size++;
		return (solvehelper(blocks, map, size, idx));
    }
	temp = duplicate(blocks);
	temp[idx].shape = shift(temp[i].shape, size);
    return (solvehelper(blocks, (map | blocks[idx].shape), size, idx + 1 ) || solvehelper(temp, map, size, idx));
}
