/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:31:44 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/28 14:52:50 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	top_row(unsigned long long *d, int s, int i)
{
	int count;
	
	count = 0;
	if (i % s == 0)
		count += valid(d, s, i + 1);
	else if ((i + 1) % s == 0)
		count += valid(d, s, i - 1);
	else
	{	
		count += valid(d, s, i - 1);
		count += valid(d, s, i + 1);
	}
	count += valid(d, s, i - s);
	return (count);
}

int	bottom_row(unsigned long long *d, int s, int i)
{

	int count;

	count = 0;
	if (i % s == 0)
		count += valid(d, s, i + 1);
	else if ((i + 1) % s == 0)
		count += valid(d, s, i - 1);
	else
	{
		count += valid(d, s, i - 1);
		count += valid(d, s, i + 1);
	}
	count += valid(d, s, i + s);
	return (count);
}

int	left_side(unsigned long long *d, int s, int i)
{
	int count;

	count = 0;
	count += valid(d, s, i + s);
	count += valid(d, s, i - s);
	count += valid(d, s, i - 1);
	return (count);
}

int	right_side(unsigned long long *d, int s, int i, int all)
{
	int count;

	count = 0;
	count += valid(d, s, i + s);
	count += valid(d, s, i - s);
	count += valid(d, s, i + 1);
	if (all)
		count += valid(d, s, i - 1);
	return (count);

}

int	valid(unsigned long long *d, int s, int i)
{
	if (i == -1)
	{
		i = 0;
		while (i < s * s)
		{
			if ((*d >> i) & 1)
				break ;
			i++;
		}
	}
	if ((*d >> i) & 1)
	{
		*d = unset_bit(*d, i);
		if (i >= s * (s - 1))
			return (1 + top_row(d, s, i));
		if (i < s)
			return (1 + bottom_row(d, s, i));
		if ((i + 1) % s == 0)
			return (1 + left_side(d, s, i));
		if (i % s == 0)
			return (1 + right_side(d, s, i, 0));
		else
			return (1 + right_side(d, s, i, 1));
	}
	return (0);
}

int	check_box(unsigned long long block, int size)
{
	return ((int)block + size);
}
