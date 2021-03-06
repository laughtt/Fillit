/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:53:37 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/28 17:47:36 by jcarpio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FILLIT_H
# define FILLIT_H
# define MAX_TETROMINOS 26

typedef struct tetrominos
{
	long	shape;
	char 	id;
}		tet_s;


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
unsigned long long	reset_block(unsigned long long block, int size);
unsigned long long	remove_above(unsigned long long data, int group, int size);
tet_s				*solve(tet_s (*blocks)[], int idx, int size);
void				display_usage(char *program_name);
int					ft_check_parallels(unsigned int num);
int					ft_check_adjacents(int adjacents, int count);
int					ft_check_bits(int num, int *bites, int size);
unsigned int		ft_line_to_int(char *line);
int					ft_check_box(int num, int line_box_pos);
int					ft_add_to_struct(char *line, tet_s (*tet)[], int line_box_pos, int *tet_pos);
int					ft_check_line(char *line, int line_box_pos);
int					ft_get_input(int fd, tet_s (*tet)[], int *size);
int					check_fit(unsigned long long map, long block);

#endif
