/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:30:56 by majullie          #+#    #+#             */
/*   Updated: 2016/12/09 08:38:19 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		parse_input(char *filename, t_ress *p_ress)
{
	int			ret;
	char		bf[21];
	t_tetri		*tetri;
	char		sign;

	if ((p_ress->fd = open(filename, O_RDONLY)) == -1)
		die("error");
	sign = 'A';
	while ((ret = read(p_ress->fd, bf, 21)) == 21)
	{
		tetri = parse_tetri(bf, 21, p_ress);
		tetri->sign = sign++;
		ft_llist_add_last(p_ress->lst, tetri, sizeof(t_tetri));
	}
	if (ret != 20)
		free_and_die(p_ress, "error");
	if (ret == 20)
	{
		tetri = parse_tetri(bf, 20, p_ress);
		tetri->sign = sign++;
		ft_llist_add_last(p_ress->lst, tetri, sizeof(t_tetri));
	}
	if (close(p_ress->fd) == -1)
		die("error");
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
		coord.x++;
		i++;
	}
	return (coord.min_x + coord.min_y * 5);
}
