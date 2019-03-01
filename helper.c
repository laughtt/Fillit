/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:52:10 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/28 14:57:46 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned long long	*cpy(unsigned long long data)
{
	g_pointers[g_pointer_cnt] = data;
	return (&g_pointers[g_pointer_cnt++]);
}

int		top_has_one(unsigned long long block, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if ((block >> ((size * (size - 1)) + i)) & 1)
			return (1);
		i++;
	}
	return (0);
}

unsigned long long	reset_block(unsigned long long block, int size)
{
	while (42)
	{
		if (valid(cpy(block), size, -1) == 4 && top_has_one(block, size) && !(valid(cpy(block << 1), size, -1) == 4))
			return (block);
		block = block << 1;
	}
}

unsigned long long	unset_bit(unsigned long long data, int pos)
{
	if ((data >> pos) & 1)
		return (data & ~(1 << pos));
	return (data);
}

unsigned long long	remove_above(unsigned long long data, int group, int size)
{
	int top;
	int bottom;

	group = group + 1;
	top = size * size;
	bottom = (group * size) - size;
	while (bottom < top)
	{
		data = unset_bit(data, bottom);
		bottom++;
	}
	return (data);
}

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
		new = new | temp;
		pos--;
		i++;
	}
	return (new);
}

int					check_fit(unsigned long long map, long block)
{
	return ((map & block) ? 1 : 0);
}

int					check_over(unsigned long long data, int size)
{
	int tot;
	int i;

	tot = 0;
	i = -1;
	while (++i < (size*size))
		tot = tot + (((data >> i) & 1) * ((i / size) + 1));
	return (tot);
}

unsigned long long	shift(unsigned long long data, int size)
{
	if (check_over(data, size) == check_over(data >> 1, size))
		data = data >> 1;
	else if (valid(cpy(data >> 1), size, -1) == 4)
		data = data >> 1;
	else if ((data & 1) == 1 && !(valid(cpy(data >> 1), size, -1) == 4))
		return (0);
	else
		return (shift(data >> 1, size));
	return (data);
}
