/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhennigh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 19:07:14 by nhennigh          #+#    #+#             */
/*   Updated: 2019/02/28 14:57:10 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H
# define MAX_TETROMINOS 26

typedef struct 	tetrominos
{
   	long	shape;
	char 	id;
}			tet_s;

static unsigned long long	g_pointers[10000];
static int					g_pointer_cnt = 0;

int					check_over(unsigned long long data, int size);
unsigned long long	shift(unsigned long long data, int size);
unsigned long long	increase_map(unsigned long long map, int size);
unsigned long long	unset_bit(unsigned long long data, int pos);
unsigned long long	remove_range(unsigned long long data, int group, int size);
int					valid(unsigned long long *d, int s, int i);
int					left_side(unsigned long long *d, int s, int i);
int					right_side(unsigned long long *d, int s, int i, int all);
int					top_row(unsigned long long *d, int s, int i);
int					bottom_row(unsigned long long *d, int s, int i);
int					check_box(unsigned long long block, int size);
tet_s				*solve(tet_s (*blocks)[], int idx, int size);

#endif
