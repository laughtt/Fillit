/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 15:53:37 by jcarpio-          #+#    #+#             */
/*   Updated: 2019/02/27 16:21:23 by jcarpio-         ###   ########.fr       */
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

void			display_usage(char *program_name);
int				ft_check_parallels(unsigned int num);
int				ft_check_adjacents(int adjacents, int count);
int				ft_check_bits(int num, int *bites, int size);
unsigned int	ft_line_to_int(char *line);
int				ft_check_box(int num, int line_box_pos);
int				ft_add_to_struct(char *line, tet_s (*tet)[], int line_box_pos, int *tet_pos);
int				ft_check_line(char *line, int line_box_pos);
int				ft_get_input(int fd, tet_s (*tet)[]);

#endif
