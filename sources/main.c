#include "fillit.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

int			main(int argc, char *argv[])
{
	t_llist		*lst_tetris;
	t_ress		ress;
	char		**grid;
	int			grid_size;

	if (argc != 2)
		die("usage: fillit input_file");
	ft_llist_create(&lst_tetris);
	if (lst_tetris == NULL)
		die("error1");
	ress.lst = lst_tetris;
	parse_input(argv[1], &ress);
	ft_llist_foreach(lst_tetris, (void *)&print);
	if ((grid_size = init_grid(&grid, lst_tetris->size * 4)) == -1)
		free_and_die(&ress, "error");
	solve(lst_tetris, grid, grid_size);
	print_grid(grid, grid_size);
	ft_llist_destroy(&lst_tetris);
	return (0);
}

void		place_tetri(t_llist *lst_tetris, char **grid, int grid_size, int *status)
{
	char		sign;
	t_llnode	*cur;
	size_t		placed;
	int			coord;

	cur = lst_tetris->first;
	sign = 'A';
	place(cur, grid, grid_size, sign);
	placed = 0;
	status[placed++] = 1;
	while (cur != NULL)
	{
		if ((coord = place(cur->next, grid, grid_size, sign)) > 0)
		{
			status[placed++] = 1;
			sign++;
		}
		else
		{
			unfill_grid(cur->val, grid, coord);
			status[placed--] = 0;
			sign--;
		}
	}
}

void		unfill_grid(t_tetri tetri, char **grid, int coord)
{
	int		i;
	int		j;
	int		x_tetri;
	int		y_tetri;
	int		block;

	j = coord % 10;
	i = coord / 10;
	block = 0;
	while (block < 4)
	{
		x_tetri = tetri->coord[block * 2] - '0';
		y_tetri = tetri->coord[block * 2 + 1] - '0';
		grid[j + y_tetri][i + x_tetri] = '.';
		block++;
	}
}


int			place(t_llnode *cur, char **grid, int grid_size, char sign)
{
	int			i;
	int			j;

	i = 0;
	while (i < grid_size)
	{
		//printf("ligne=%d sign=%c\n", i, sign);
		//printf("sz=%d\n", grid_size);
		j = 0;
		while (j < grid_size)
		{
			if (fill_grid((t_tetri)cur->val, grid, sign, j, i, grid_size) == 1)
			{
				print_grid(grid, grid_size);
				puts("=====");
				return (j + i * 10);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void		solve(t_llist *lst_tetris, char **grid, int grid_size)
{
	int			*status;
	size_t		i;

	if (!(status = ft_memalloc(lst_tetris->size)))
		die("error");
	i = 0;
	while (i < lst_tetris->size)
	{
		status[i] = 0;
		i++;
	}
	place_tetri(lst_tetris, grid, grid_size, status);
	i = 0;
	while (i < lst_tetris->size)
	{
		if (status[i] == 0)
		{
			grid_size++;
			if ((alloc_grid(&grid, grid_size)) == -1)
				die("error");
			place_tetri(lst_tetris, grid, grid_size, status);
		}
		i++;
	}
}

int			alloc_grid(char ***p_grid, int grid_size)
{
	int		i;
	char	**grid;

	if (!(grid = (char **)malloc(sizeof(char *) * grid_size)))
		return -1;
	i = 0;
	while (i < grid_size)
	{
		if (!(grid[i] = (char *)malloc(sizeof(char) * grid_size)))
			return -1;
		ft_memset(grid[i], '.', grid_size);
		i++;
	}
	*p_grid = grid;
	return (1);
}

int			fill_grid(t_tetri tetri, char **grid, char sign, int x_cell, int y_cell, int grid_size)
{
	int		block;
	int		x_tetri;
	int		y_tetri;

	block = 0;
	while (block < 4)
	{
		x_tetri = tetri->coord[block * 2] - '0';
		y_tetri = tetri->coord[block * 2 + 1] - '0';
		if ((x_cell + x_tetri) >= grid_size
				|| (y_cell + y_tetri) >= grid_size
				|| grid[y_cell + y_tetri][x_cell + x_tetri] != '.' /*|| grid[y_cell][x_cell + x_tetri] != '.'*/)
		{
			//printf("Grid ko = %c\n", grid[y_cell + y_tetri][x_cell + x_tetri]);
			return (0);
		}
		//printf("Grid ok = %c\n", grid[y_cell + y_tetri][x_cell + x_tetri]);
		block++;
	}
	block = 0;
	while (block < 4)
	{
		x_tetri = tetri->coord[block * 2] - '0';
		y_tetri = tetri->coord[block * 2 + 1] - '0';
		grid[y_cell + y_tetri][x_cell + x_tetri] = sign;
		//	grid[y_cell][x_cell + x_tetri] = sign;
		block++;
	}
	return (1);
}

void		print_grid(char **grid, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putendl(grid[i]);
		i++;
	}
}


int			init_grid(char ***p_grid, int size)
{
	int		i;
	int		j;
	char	**grid;

	i = 2;
	while (i * i < size)
		i++;
	if (!(grid = (char **)malloc(sizeof(char *) * i)))
		return -1;
	j = 0;
	while (j < i)
	{
		if (!(grid[j] = (char *)malloc(sizeof(char) * i)))
			return -1;
		ft_memset(grid[j], '.', i);
		j++;
	}
	*p_grid = grid;
	return (i);
}





void		print(void *tetri)
{
	printf("%s\n", (char *)tetri);
}


void		die(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void		free_and_die(t_ress *p_ress, char *str)
{
	ft_llist_destroy(&(p_ress->lst));
	close(p_ress->fd);
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void		parse_input(char *filename, t_ress *p_ress)
{
	int			ret;
	char		bf[21];
	size_t		sz_tetri;

	if ((p_ress->fd = open(filename, O_RDONLY)) == -1)
		die("error2");
	sz_tetri = sizeof(t_tetri);
	while ((ret = read(p_ress->fd, bf, 21)) == 21)
		ft_llist_add_last(p_ress->lst, parse_tetri(bf, 21, p_ress), sz_tetri);
	if (ret != 20)
		free_and_die(p_ress, "error3");
	if (ret == 20)
		ft_llist_add_last(p_ress->lst, parse_tetri(bf, 20, p_ress),	sz_tetri);
	if (close(p_ress->fd) == -1)
		die("error4");
}

t_tetri		parse_tetri(char *bf, size_t len, t_ress *p_ress)
{
	t_tetri		tetri;
	int			o;
	int			i;
	int			block;

	tetri = ft_memalloc(sizeof(t_tetri));
	check_bf(bf, len, p_ress);
	tetri->coord = ft_strnew(8);
	o = get_origin(bf);
	i = o;
	block = 0;
	while (block < 4)
	{
		if (bf[i] == '#')
		{
			tetri->coord[block * 2] = (i - o) % 5 + '0';
			tetri->coord[block * 2 + 1] = (i - o) / 5 + '0';
			block++;
		}
		i++;
	}
	check_tetri(tetri, p_ress);
	return (tetri);
}


int			get_origin(char *bf)
{
	t_coord	coord;
	int		i;

	coord.x = 0;
	coord.y = 0;
	coord.min_x = 4;
	coord.min_y = 4;
	i = 0;
	while (i < 19)
	{
		if (bf[i] == '#')
		{
			coord.min_x = (coord.min_x > coord.x) ? coord.x : coord.min_x;
			coord.min_y = (coord.min_y > coord.y) ? coord.y : coord.min_y;
		}
		if (bf[i] == '\n')
		{
			coord.y++;
			coord.x = -1;
		}
		i++;
		coord.x++;
	}
	return (coord.min_x + coord.min_y * 5);
}

//reverifier toutes les formes
void		check_tetri(t_tetri tetri, t_ress *p_ress)
{
	if ((ft_strcmp(tetri->coord, "00102030") != 0)
			&& (ft_strcmp(tetri->coord, "00010203") != 0)
			&& (ft_strcmp(tetri->coord, "00100111") != 0)
			&& (ft_strcmp(tetri->coord, "00102001") != 0)
			&& (ft_strcmp(tetri->coord, "00101112") != 0)
			&& (ft_strcmp(tetri->coord, "20011121") != 0)
			&& (ft_strcmp(tetri->coord, "00010112") != 0)
			&& (ft_strcmp(tetri->coord, "00102021") != 0)
			&& (ft_strcmp(tetri->coord, "10110212") != 0)
			&& (ft_strcmp(tetri->coord, "00011121") != 0)
			&& (ft_strcmp(tetri->coord, "00100102") != 0)
			&& (ft_strcmp(tetri->coord, "10200111") != 0)
			&& (ft_strcmp(tetri->coord, "00011112") != 0)
			&& (ft_strcmp(tetri->coord, "00101121") != 0)
			&& (ft_strcmp(tetri->coord, "10011102") != 0)
			&& (ft_strcmp(tetri->coord, "10011121") != 0)
			&& (ft_strcmp(tetri->coord, "00011102") != 0)
			&& (ft_strcmp(tetri->coord, "00102011") != 0)
			&& (ft_strcmp(tetri->coord, "10011112") != 0)
			&& (ft_strcmp(tetri->coord, "00010212") != 0))
		free_and_die(p_ress, "error9");
}

void		check_bf(char *bf, size_t len, t_ress *p_ress)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if ((bf[i] != '.' && bf[i] != '#')
				|| (bf[i + 1] != '.' && bf[i + 1] != '#')
				|| (bf[i + 2] != '.' && bf[i + 2] != '#')
				|| (bf[i + 3] != '.' && bf[i + 3] != '#')
				|| (bf[i + 4] != '\n'))
			free_and_die(p_ress, "error6");
		i += 5;
	}
	if (len == 21 && bf[20] != '\n')
		free_and_die(p_ress, "error7");
	check_count(bf, p_ress);
}

void		check_count(char *bf, t_ress *p_ress)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (bf[i] == '#')
			count++;
		i++;
	}
	if (count != 4)
		free_and_die(p_ress, "error8");
}
