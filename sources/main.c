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
	t_llist		*tetris;
	t_ress		*ress;
	char		**grid;
	int			grid_size;
	int			size;

	if (argc != 2)
		die("usage: fillit input_file");
	ft_llist_create(&tetris);
	if (tetris == NULL)
		die("error");
	ress = ft_memalloc(sizeof(t_ress));
	ress->lst = tetris;
	parse_input(argv[1], ress);

	ft_llist_foreach(tetris, (void *)&print);

	grid_size = 2;
	size = tetris->size * 4;
	while (grid_size * grid_size < size)
		grid_size++;
	if (grid_alloc(&grid, grid_size) == -1)
		free_and_die(ress, "error");
	grid_size = solve(tetris, grid, grid_size);
	print_grid(tetris, grid, grid_size);
	ft_llist_destroy(&tetris);

	return (0);
}

int			solve(t_llist *tetris, char **grid, int grid_size)
{
	while (!solve_grid(tetris, grid, grid_size, 0, 0) && grid_size < 7)
	{
		grid_size++;
		if ((grid_alloc(&grid, grid_size)) == -1)
			die("error");
	}
	return (grid_size);
}

int			solve_grid(t_llist *tetris, char **grid, int grid_size, int x, int y)
{
	t_llnode	*cur;

	print_grid(tetris, grid, grid_size);

	while (1)
	{
		cur = tetris->first;
		while (cur != NULL && ((t_tetri *)cur->val)->position != -1)
			cur = cur->next;

		printf("On va tester le tetri %c qui est en %d\n", ((t_tetri *)cur->val)->sign, ((t_tetri *)cur->val)->position);


		if (cur != NULL && ((((t_tetri *)cur->val)->position = place(cur, grid, grid_size)) >= 0))
		{
			printf("On a place %c en %d\n", ((t_tetri *)cur->val)->sign, ((t_tetri *)cur->val)->position);
			cur = tetris->first;
			while (cur != NULL && ((t_tetri *)cur->val)->position != -1)
				cur = cur->next;
			if (cur == NULL)
				return (1);
			if (solve_grid(tetris, grid, grid_size) == 1)
			{
				return (1);
			}
			else
			{

				printf("On efface le tetri %c qui est en %d\n", ((t_tetri *)cur->val)->sign, ((t_tetri *)cur->val)->position);
				clear_tetri((t_tetri *)cur->val, grid);
			}
		}
		if (cur != NULL)
((t_tetri *)cur->val)->position = -2;
	}
	printf("Il n'y a plus de tetri a placer\n");
	return (0);
}

void		clear_tetri(t_tetri *tetri, char **grid)
{
	int		block;
	int		x;
	int		y;
	int		x0;
	int		y0;

	block = 0;
	x0 = tetri->position / 100;
	y0 = tetri->position % 100;
	while (block < 4)
	{
		x = tetri->coord[block * 2] - '0';
		y = tetri->coord[block * 2 + 1] - '0';
		grid[y0 + y][x0 + x] = '.';
		block++;
	}
	tetri->position = -1;
}

int			place(t_llnode *cur, char **grid, int grid_size)
{
	int			i;
	int			j;

	i = 0;
	while (i < grid_size)
	{
		j = 0;
		while (j < grid_size)
		{
			if (try_each_block(((t_tetri *)cur->val)->coord, grid, j, i, grid_size) == 1)
				return (j + i * 100);
			j++;
		}
		i++;
	}
	return (-1);
}

int			try_each_block(char *coord, char **grid, int x0, int y0, int grid_size)
{
	int		block;
	int		x;
	int		y;

	block = 0;
	while (block < 4)
	{
		x = coord[block * 2] - '0';
		y = coord[block * 2 + 1] - '0';
		if ((x0 + x) >= grid_size
				|| (y0 + y) >= grid_size
				|| grid[y0 + y][x0 + x] != '.')
		{
			//printf("Grid ko = %c\n", grid[y0 + y][x0 + x]);
			printf("On ne peut pas placer le tetri en x=%d y=%d\n", x0, y0);
			return (0);
		}
		//printf("Grid ok = %c\n", grid[y0 + y][x0 + x]);
		block++;
	}
	block = 0;
	while (block < 4)
	{
		x = coord[block * 2] - '0';
		y = coord[block * 2 + 1] - '0';
		grid[y0 + y][x0 + x] = '#';
		block++;
	}
	return (1);
}

void		print_tetri(t_tetri *tetri, char **grid)
{
	int		x0;
	int		y0;
	int		x;
	int		y;
	int		block;

	block = 0;
	while (block < 4)
	{
		x0 = tetri->position / 100;
		y0 = tetri->position % 100;
		x = tetri->coord[block * 2] - '0';
		y = tetri->coord[block * 2 + 1] - '0';
		grid[y0 + y][x0 + x] = tetri->sign;
		block++;
	}
}

void		print_grid(t_llist *tetris, char **grid, int size)
{
	int			i;
	t_llnode	*cur;

	cur = tetris->first;
	cur = cur->next;
	/*
	while (cur != NULL)
	{
		print_tetri(cur->val, grid);
		cur = cur->next;
	}
*/
	i = 0;
	while (i < size)
	{
		ft_putendl(grid[i]);
		i++;
	}
}




void		print(t_tetri *tetri)
{
	printf("%c\n", tetri->sign);
	printf("%s\n", tetri->coord);
	printf("%d\n", tetri->position);
	puts("---------");
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
	t_tetri		*tetri;
	char		sign;

	if ((p_ress->fd = open(filename, O_RDONLY)) == -1)
		die("error2");
	sign = 'A';
	while ((ret = read(p_ress->fd, bf, 21)) == 21)
	{
		tetri = parse_tetri(bf, 21, p_ress);
		tetri->sign = sign++;
		ft_llist_add_last(p_ress->lst, tetri, sizeof(t_tetri));
	}
	if (ret != 20)
		free_and_die(p_ress, "error3");
	if (ret == 20)
	{
		tetri = parse_tetri(bf, 20, p_ress);
		tetri->sign = sign++;
		ft_llist_add_last(p_ress->lst, tetri, sizeof(t_tetri));
	}
	if (close(p_ress->fd) == -1)
		die("error4");

}

t_tetri		*parse_tetri(char *bf, size_t len, t_ress *p_ress)
{
	t_tetri		*tetri;
	int			o;
	int			i;
	int			block;

	if (!(tetri = ft_memalloc(sizeof(t_tetri))))
			free_and_die(p_ress, "error");
	check_bf(bf, len, p_ress);
	tetri->position = -1;
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

//reverifier toutes les formes
void		check_tetri(t_tetri *tetri, t_ress *p_ress)
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

int			get_origin(char *bf)
{
	int		x;
	int		y;
	int		min_x;
	int		min_y;
	int		i;

	x = 0;
	y = 0;
	min_x = 4;
	min_y = 4;
	i = 0;
	while (i < 19)
	{
		if (bf[i] == '#')
		{
			min_x = (min_x > x) ? x : min_x;
			min_y = (min_y > y) ? y : min_y;
		}
		if (bf[i] == '\n')
		{
			y++;
			x = -1;
		}
		i++;
		x++;
	}
	return (min_x + min_y * 5);
}

int			grid_alloc(char ***p_grid, int grid_size)
{
	int		i;
	char	**grid;

	if (!(grid = (char **)malloc(sizeof(char *) * grid_size)))
		return (-1);
	i = 0;
	while (i < grid_size)
	{
		if (!(grid[i] = (char *)malloc(sizeof(char) * grid_size)))
			return (-1);
		ft_memset(grid[i], '.', grid_size);
		i++;
	}
	*p_grid = grid;
	return (1);
}
