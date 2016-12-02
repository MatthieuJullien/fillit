#ifndef FILLIT_H
# define FILLIT_H 

#include "libft.h"

typedef struct	s_tetri
{
	char		*coord;
	int			position;
}				*t_tetri;

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

void		die(char *str);
void		free_and_die(t_ress *p_ress, char *str);
void		parse_input(char *filename, t_ress *p_ress);
t_tetri		parse_tetri(char *buf, size_t len, t_ress *p_ress);
void		check_tetri(t_tetri tetri, t_ress *p_ress);
void		check_bf(char *bf, size_t len, t_ress *p_ress);
void		check_count(char *bf, t_ress *p_ress);
int			get_origin(char *bf);
void		print_grid(char **grid, int size);
int			init_grid(char ***p_grid, int size);
int			fill_grid(t_tetri tetri, char **grid, char sign, int x_cell, int y_cell, int grid_size);
void		solve(t_llist *lst_tetris, char **grid, int grid_size);
int			alloc_grid(char ***p_grid, int grid_size);
void		unfill_grid(t_tetri tetri, char **grid, int coord);
int			place(t_llnode *cur, char **grid, int grid_size, char sign);

void		print(void *tetri);

#endif
