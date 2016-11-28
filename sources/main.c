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
	t_llist			*lst_tetris;
	t_ress	ress;

	if (argc != 2)
		die("usage: fillit input_file");
	ft_llist_create(&lst_tetris);
	if (lst_tetris == NULL)
		die("error1");
	ress.lst = lst_tetris;
	parse_input(argv[1], &ress);
	ft_llist_foreach(lst_tetris, (void *)&print);
	return (0);
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
	int			i;
	int			coord;
	int			block;

	check_bf(bf, len, p_ress);
	tetri = ft_strnew(8);
	i = get_origin(bf);
	printf("i=%d\n", i);
	coord = 0;
	block = 0;
	while (i < 19)
	{
		while (bf[i] != '\n')
		{
			if (bf[i] == '#')
			{
				tetri[block * 2] = coord % 10 + '0';
				tetri[block * 2 + 1] = coord / 10 + '0';
				block++;
			}
			coord += 1;
			i++;
		}
		coord = coord + 10 - (coord % 10);
		i++;
	}
	//check_tetri(tetri, p_ress);
	return (tetri);
}


int			get_origin(char *bf)
{
	int		i;
	int		j;
	int		origin;

	i = 0;
	j = 0;
	origin = -1;
	while (bf[i] != '#')
		i++;
	while (bf[i + 1 + j] != '\n')
	{
		if (bf[i + j] == '#')
		{
			origin = i;
			break;
		}
		j++;
	}
	if (origin == -1)
	{
		while (bf[i + j] != '#')
			j++;
		origin = i + j - 5;
	}
	return (origin);
}
/*
void		check_tetri(t_tetri tetri, t_ress *p_ress)
{
	if ((ft_strcmp(tetri, "00102030") != 0)
			|| (ft_strcmp(tetri, "00010203") != 0)
			|| (ft_strcmp(tetri, "00011011") != 0)
			|| (ft_strcmp(tetri, "") != 0)
			|| (ft_strcmp(tetri, "") != 0)
			|| (ft_strcmp(tetri, "") != 0)
			|| (ft_strcmp(tetri, "") != 0)
			|| (ft_strcmp(tetri, "") != 0)
			|| (ft_strcmp(tetri, "") != 0)
			|| (ft_strcmp(tetri, "") != 0)
			|| (ft_strcmp(tetri, "") != 0)
			|| (ft_strcmp(tetri, "") != 0)
			|| (ft_strcmp(tetri, "") != 0)
			|| (ft_strcmp(tetri, "") != 0)
			|| (ft_strcmp(tetri, "") != 0)
			|| (ft_strcmp(tetri, "") != 0)
			|| (ft_strcmp(tetri, "") != 0)
			|| (ft_strcmp(tetri, "") != 0))
}
*/
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
