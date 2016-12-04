#ifndef FILLIT_H
# define FILLIT_H 

#include "libft.h"

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


void		die(char *str);
void		parse_input(char *filename, t_ress *p_ress);
t_tetri		*parse_tetri(char *bf, size_t len, t_ress *p_ress);
void		check_bf(char *bf, size_t len, t_ress *p_ress);
void		check_count(char *bf, t_ress *p_ress);
void		check_tetri(t_tetri *tetri, t_ress *p_ress);
int			get_origin(char *bf);
void		free_and_die(t_ress *p_ress, char *str);

int			grid_alloc(char ***p_grid, int grid_size);
void		solve(t_llist *tetris, char **grid, int grid_size);
int			solve_grid(t_llist *tetris, char **grid, int grid_size);
int			place(t_llnode *cur, char **grid, int grid_size);
int			try_each_block(char *coord, char **grid, int x_cell, int y_cell, int grid_size);
void		print_tetri(t_tetri *tetri, char **grid);
void		print_grid(t_llist *tetris, char **grid, int size);

void		print(t_tetri *tetri);

#endif
