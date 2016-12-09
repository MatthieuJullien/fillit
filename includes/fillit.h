/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:22:04 by majullie          #+#    #+#             */
/*   Updated: 2016/12/09 09:28:50 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_tetri
{
	char		sign;
	char		*coord;
	int			position;
}				t_tetri;

typedef struct	s_ress
{
	int			fd;
	int			grid_size;
	t_llist		*lst;
}				t_ress;

typedef struct	s_coord
{
	int			x;
	int			y;
	int			min_x;
	int			min_y;
}				t_coord;

typedef struct	s_grid
{
	char		**map;
	int			size;
}				t_grid;

void			die(char *str);
void			free_and_die(t_ress *p_ress, char *str);
void			clear(void *data);
void			parse_input(char *filename, t_ress *p_ress);
t_tetri			*parse_tetri(char *bf, size_t len, t_ress *p_ress);
void			check_bf(char *bf, size_t len, t_ress *p_ress);
void			check_count(char *bf, t_ress *p_ress);
void			check_tetri(t_tetri *tetri, t_ress *p_ress);
int				get_origin(char *bf);
int				grid_alloc(char ***p_grid, int grid_size);
void			free_grid(t_grid **grid);
void			solve(t_llist *tetris, t_grid *grid);
int				solve_grid(t_llist *tetris, t_llnode *cur, t_grid *grid, int i);
int				try_each_block(t_tetri *tetri, t_grid *grid, int x0, int y0);
void			clear_tetri(t_tetri *tetri, char **grid);
void			print_grid(t_llist *tetris, char **grid, int size);
void			free_env(t_ress *ress, t_grid *grid);

#endif
