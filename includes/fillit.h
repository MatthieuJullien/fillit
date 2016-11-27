#ifndef FILLIT_H
# define FILLIT_H 

#include "libft.h"

typedef struct	s_tetri
{
	char		coord[4][2]; 
}				t_tetri;

void		die(char *str);
void		close_and_die(int fd, char *str);
void		parse_input(char *filename, t_llist *lst_tetris);
t_tetri		*parse_tetri(char *buf, size_t len, int fd);
void		check_bf(char *bf, size_t len, int fd);
void		check_count(char *bf, int fd);

#endif
