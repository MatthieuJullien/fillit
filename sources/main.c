/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:04:37 by majullie          #+#    #+#             */
/*   Updated: 2016/12/09 09:35:09 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char *argv[])
{
	t_llist		*tetris;
	t_ress		*ress;
	t_grid		*grid;
	int			size;

	if (argc != 2)
		die("usage: fillit input_file");
	ft_llist_create(&tetris);
	ress = ft_memalloc(sizeof(t_ress));
	grid = ft_memalloc(sizeof(t_grid));
	if (!tetris || !ress || !grid)
		die("error");
	ress->lst = tetris;
	parse_input(argv[1], ress);
	grid->size = 2;
	size = tetris->size * 4;
	while (grid->size * grid->size < size)
		grid->size++;
	if (grid_alloc(&grid->map, grid->size) == -1)
		free_and_die(ress, "error");
	solve(tetris, grid);
	free_env(ress, grid);
	return (0);
}

void		free_env(t_ress *ress, t_grid *grid)
{
	free_grid(&grid);
	ft_llist_foreach(ress->lst, clear);
	ft_llist_destroy(&(ress->lst));
	free(ress);
}

void		clear(void *data)
{
	t_tetri *tetri;

	tetri = (t_tetri *)data;
	free(tetri->coord);
}

void		die(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void		free_and_die(t_ress *p_ress, char *str)
{
	close(p_ress->fd);
	ft_putendl(str);
	exit(EXIT_FAILURE);
}
