/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:38:21 by majullie          #+#    #+#             */
/*   Updated: 2016/12/07 11:38:52 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void		print_grid(t_llist *tetris, char **grid, int size)
{
	int			i;
	t_llnode	*cur;

	cur = tetris->first;
	cur = cur->next;
	i = 0;
	while (i < size)
	{
		ft_putendl(grid[i]);
		i++;
	}
}
