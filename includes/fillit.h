#ifndef FILLIT_H
# define FILLIT_H 

#include "libft.h"

typedef char	*t_tetri;

typedef struct	s_ress
{
	int			fd;
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

void		print(void *tetri);

#endif
