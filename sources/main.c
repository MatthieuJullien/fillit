#include "fillit.h"
#include "libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int			main(int argc, char *argv[])
{
	t_llist		*lst_tetris;

	if (argc != 2)
		die("usage: fillit input_file");
	ft_llist_create(&lst_tetris);
	if (lst_tetris == NULL)
		die("error1");
	parse_input(argv[1], lst_tetris);
	return (0);
}

void		die(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void		close_and_die(int fd, char *str)
{
	close(fd);
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void		parse_input(char *filename, t_llist *lst_tetris)
{
	int			fd;
	int			ret;
	char		bf[21];
	size_t		sz_tetri;

	if ((fd = open(filename, O_RDONLY)) == -1)
		die("error2");
	sz_tetri = sizeof(t_tetri);
	while ((ret = read(fd, bf, 21)) == 21)
		ft_llist_add_last(lst_tetris, parse_tetri(bf, 21, fd), sz_tetri);
	if (ret != 20)
		close_and_die(fd, "error3");
	if (ret == 20)
		ft_llist_add_last(lst_tetris, parse_tetri(bf, 20, fd), sz_tetri);
	if (close(fd) == -1)
		die("error4");
}

t_tetri		*parse_tetri(char *bf, size_t len, int fd)
{
	check_bf(bf, len, fd);

	return NULL;//stub
	//...
}

void		check_bf(char *bf, size_t len, int fd)
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
			close_and_die(fd, "error6");
		i += 5;
	}
	if (len == 21 && bf[20] != '\n')
		close_and_die(fd, "error7");
	check_count(bf, fd);
}

void		check_count(char *bf, int fd)
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
		close_and_die(fd, "error8");
}
