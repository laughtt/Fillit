/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:08:08 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/28 17:15:36 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fillit.h"

void		display_usage(char *program_name)
{
	ft_putstr("usage: ");
	ft_putstr(program_name + 2);
	ft_putstr(" source_file\n");
}

int		ft_check_parallels(unsigned int num)
{
	unsigned char	first_8bits;
	unsigned char	first_4bits;

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
	size = 0;
	paralle = num;
	adjacents = num - ((num >> 4) << 4);
	if (*bites > 1 && *bites < 4)
		if (!ft_check_parallels(paralle))
			return (0);
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
